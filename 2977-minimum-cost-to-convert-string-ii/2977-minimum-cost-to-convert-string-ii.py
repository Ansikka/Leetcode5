from typing import List
from functools import cache
from math import inf


class TrieNode:
    """Trie node for storing string patterns"""
    __slots__ = ["children", "word_id"]
  
    def __init__(self):
        # Array of 26 children nodes (one for each lowercase letter)
        self.children: List[TrieNode | None] = [None] * 26
        # ID assigned to complete words ending at this node (-1 if not a word ending)
        self.word_id = -1


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        """
        Find minimum cost to transform source string to target string using given transformations.
      
        Args:
            source: Source string to transform
            target: Target string to achieve
            original: List of original substrings that can be replaced
            changed: List of replacement substrings
            cost: List of costs for each transformation
          
        Returns:
            Minimum cost to transform source to target, or -1 if impossible
        """
        num_transformations = len(cost)
        # Initialize adjacency matrix for shortest path calculation
        # Size is doubled to accommodate all possible unique strings
        max_nodes = num_transformations << 1  # num_transformations * 2
        graph = [[inf] * max_nodes for _ in range(max_nodes)]
      
        # Distance from any node to itself is 0
        for i in range(max_nodes):
            graph[i][i] = 0
      
        # Initialize trie root and word counter
        trie_root = TrieNode()
        word_counter = 0
      
        def insert_word(word: str) -> int:
            """
            Insert a word into the trie and return its unique ID.
          
            Args:
                word: String to insert into trie
              
            Returns:
                Unique ID assigned to this word
            """
            nonlocal word_counter
            current_node = trie_root
          
            # Traverse/build trie path for the word
            for char in word:
                char_index = ord(char) - ord('a')
                if current_node.children[char_index] is None:
                    current_node.children[char_index] = TrieNode()
                current_node = current_node.children[char_index]
          
            # Assign unique ID if this word hasn't been seen before
            if current_node.word_id < 0:
                current_node.word_id = word_counter
                word_counter += 1
              
            return current_node.word_id
      
        @cache
        def find_min_cost(position: int) -> int:
            """
            Find minimum cost to transform source[position:] to target[position:].
            Uses dynamic programming with memoization.
          
            Args:
                position: Current position in the source/target strings
              
            Returns:
                Minimum cost to complete transformation from this position
            """
            # Base case: reached end of strings
            if position >= len(source):
                return 0
          
            # Option 1: Skip current position if characters already match
            result = find_min_cost(position + 1) if source[position] == target[position] else inf
          
            # Option 2: Try all possible substring replacements starting at current position
            source_node = trie_root
            target_node = trie_root
          
            for end_pos in range(position, len(source)):
                # Navigate both tries simultaneously
                source_char_index = ord(source[end_pos]) - ord('a')
                target_char_index = ord(target[end_pos]) - ord('a')
              
                source_node = source_node.children[source_char_index]
                target_node = target_node.children[target_char_index]
              
                # Stop if either path doesn't exist in trie
                if source_node is None or target_node is None:
                    break
              
                # Skip if either substring is not a complete word in our dictionary
                if source_node.word_id < 0 or target_node.word_id < 0:
                    continue
              
                # Try this transformation and recursively solve the rest
                transformation_cost = graph[source_node.word_id][target_node.word_id]
                result = min(result, find_min_cost(end_pos + 1) + transformation_cost)
          
            return result
      
        # Build graph of transformation costs
        for orig_str, changed_str, trans_cost in zip(original, changed, cost):
            orig_id = insert_word(orig_str)
            changed_id = insert_word(changed_str)
            # Keep minimum cost if multiple transformations exist
            graph[orig_id][changed_id] = min(graph[orig_id][changed_id], trans_cost)
      
        # Floyd-Warshall algorithm to find shortest paths between all word pairs
        for k in range(word_counter):
            for i in range(word_counter):
                # Skip if no path through k from i
                if graph[i][k] >= inf:
                    continue
                for j in range(word_counter):
                    # Update shortest path from i to j through k
                    if graph[i][k] + graph[k][j] < graph[i][j]:
                        graph[i][j] = graph[i][k] + graph[k][j]
      
        # Find minimum cost starting from position 0
        min_cost = find_min_cost(0)
      
        # Return -1 if transformation is impossible, otherwise return the cost
        return -1 if min_cost >= inf else min_cost
