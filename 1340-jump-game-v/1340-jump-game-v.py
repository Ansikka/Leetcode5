from typing import List
from functools import cache

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        """
        Find the maximum number of indices you can visit starting from any index.
        You can jump from index i to index j if:
        - i - d <= j <= i + d (j != i)
        - arr[k] < arr[i] for all k between i and j (exclusive)
      
        Args:
            arr: List of integers representing heights
            d: Maximum jump distance
          
        Returns:
            Maximum number of indices that can be visited
        """
        @cache
        def dfs(index: int) -> int:
            """
            Perform depth-first search to find max jumps from given index.
          
            Args:
                index: Current position in the array
              
            Returns:
                Maximum number of indices reachable from current index
            """
            # Start with 1 (counting current index)
            max_jumps = 1
          
            # Try jumping to the left (indices before current)
            for next_index in range(index - 1, -1, -1):
                # Stop if distance exceeds d or we hit a taller/equal element
                if index - next_index > d or arr[next_index] >= arr[index]:
                    break
                # Update max jumps if jumping to next_index gives better result
                max_jumps = max(max_jumps, 1 + dfs(next_index))
          
            # Try jumping to the right (indices after current)
            for next_index in range(index + 1, array_length):
                # Stop if distance exceeds d or we hit a taller/equal element
                if next_index - index > d or arr[next_index] >= arr[index]:
                    break
                # Update max jumps if jumping to next_index gives better result
                max_jumps = max(max_jumps, 1 + dfs(next_index))
          
            return max_jumps
      
        # Store array length for efficiency
        array_length = len(arr)
      
        # Find maximum jumps starting from each index
        return max(dfs(i) for i in range(array_length))