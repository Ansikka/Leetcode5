from typing import List
from itertools import combinations


class Solution:
    def largestSquareArea(
        self, bottomLeft: List[List[int]], topRight: List[List[int]]
    ) -> int:
        """
        Find the largest square area that can be formed from the intersection of rectangles.
      
        Args:
            bottomLeft: List of [x, y] coordinates representing bottom-left corners of rectangles
            topRight: List of [x, y] coordinates representing top-right corners of rectangles
          
        Returns:
            The area of the largest square that can be formed from rectangle intersections
        """
        max_square_area = 0
      
        # Iterate through all pairs of rectangles
        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(
            zip(bottomLeft, topRight), 2
        ):
            # Calculate the intersection rectangle dimensions
            # Width of intersection: rightmost left edge to leftmost right edge
            intersection_width = min(x2, x4) - max(x1, x3)
          
            # Height of intersection: topmost bottom edge to bottommost top edge  
            intersection_height = min(y2, y4) - max(y1, y3)
          
            # The maximum square side length is limited by the smaller dimension
            max_square_side = min(intersection_width, intersection_height)
          
            # Only consider valid intersections (positive dimensions)
            if max_square_side > 0:
                square_area = max_square_side * max_square_side
                max_square_area = max(max_square_area, square_area)
              
        return max_square_area