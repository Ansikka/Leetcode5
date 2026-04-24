class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        """
        Calculate the furthest possible distance from the origin after executing all moves.
      
        Args:
            moves: A string containing 'L' (left), 'R' (right), and '_' (wildcard) moves
      
        Returns:
            The maximum distance from origin that can be achieved
        """
        # Count the number of left moves
        left_count = moves.count("L")
      
        # Count the number of right moves
        right_count = moves.count("R")
      
        # Count the number of wildcard moves (can be either left or right)
        wildcard_count = moves.count("_")
      
        # The furthest distance is achieved by:
        # 1. Finding the absolute difference between fixed left and right moves
        # 2. Adding all wildcards in the direction that increases distance
        furthest_distance = abs(left_count - right_count) + wildcard_count
      
        return furthest_distance