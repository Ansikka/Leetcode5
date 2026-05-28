from typing import List
from math import inf


class Trie:
    """A Trie data structure for storing strings in reverse order to find longest common suffixes."""
  
    __slots__ = ("children", "length", "idx")
  
    def __init__(self):
        """Initialize a Trie node with 26 children (for lowercase English letters)."""
        # Array to store child nodes for each letter a-z
        self.children = [None] * 26
        # Store the minimum length of strings passing through this node
        self.length = inf
        # Store the index of the string with minimum length at this node
        self.idx = inf
  
    def insert(self, word: str, index: int) -> None:
        """
        Insert a word into the Trie in reverse order.
      
        Args:
            word: The string to insert
            index: The original index of the word in the container
        """
        node = self
      
        # Update root node with minimum length word information
        if node.length > len(word):
            node.length = len(word)
            node.idx = index
      
        # Insert characters in reverse order (for suffix matching)
        for char in word[::-1]:
            # Calculate the index for this character (0-25 for a-z)
            char_index = ord(char) - ord("a")
          
            # Create new node if path doesn't exist
            if node.children[char_index] is None:
                node.children[char_index] = Trie()
          
            # Move to child node
            node = node.children[char_index]
          
            # Update this node with minimum length word information
            if node.length > len(word):
                node.length = len(word)
                node.idx = index
  
    def query(self, word: str) -> int:
        """
        Find the index of the word with the longest common suffix.
      
        Args:
            word: The query string
          
        Returns:
            The index of the container word with the longest matching suffix
            and minimum length among those with the same suffix
        """
        node = self
      
        # Traverse the Trie following the reverse of the query word
        for char in word[::-1]:
            char_index = ord(char) - ord("a")
          
            # Stop if no further matching suffix exists
            if node.children[char_index] is None:
                break
          
            # Move to the next node
            node = node.children[char_index]
      
        # Return the index of the best matching word at this node
        return node.idx


class Solution:
    """Solution class for finding strings with longest common suffixes."""
  
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        """
        Find indices of container words with longest common suffix for each query.
      
        Args:
            wordsContainer: List of strings to search from
            wordsQuery: List of query strings
          
        Returns:
            List of indices where each index corresponds to the container word
            with the longest common suffix for each query word
        """
        # Build the Trie with all container words
        trie = Trie()
        for i, word in enumerate(wordsContainer):
            trie.insert(word, i)
      
        # Process each query and return results
        return [trie.query(word) for word in wordsQuery]