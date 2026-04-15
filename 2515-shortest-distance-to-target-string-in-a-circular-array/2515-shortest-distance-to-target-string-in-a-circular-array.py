class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:

        """
        Find the minimum distance from startIndex to any occurrence of target in a circular array.
      
        Args:
            words: List of strings representing the circular array
            target: The target string to search for
            startIndex: The starting position in the array
          
        Returns:
            The minimum distance to reach target, or -1 if target doesn't exist
        """
        n = len(words)
        min_distance = n  # Initialize with maximum possible distance
      
        # Iterate through all words to find occurrences of target
        for index, word in enumerate(words):
            if word == target:
                # Calculate direct distance from startIndex to current index
                direct_distance = abs(index - startIndex)
              
                # Calculate wrap-around distance (going the other way in circular array)
                wrap_distance = n - direct_distance
              
                # Update minimum distance considering both paths
                min_distance = min(min_distance, direct_distance, wrap_distance)
      
        # Return -1 if target was not found, otherwise return minimum distance
        return -1 if min_distance == n else min_distance       