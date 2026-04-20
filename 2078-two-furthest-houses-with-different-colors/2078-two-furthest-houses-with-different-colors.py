class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        """
        Find the maximum distance between two houses with different colors.
      
        Args:
            colors: List of integers representing the color of each house
          
        Returns:
            Maximum distance between two houses with different colors
        """
        max_distance = 0
        n = len(colors)
      
        # Check all pairs of houses
        for i in range(n):
            for j in range(i + 1, n):
                # If colors are different, update maximum distance
                if colors[i] != colors[j]:
                    max_distance = max(max_distance, abs(i - j))
      
        return max_distance