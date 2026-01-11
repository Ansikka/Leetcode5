class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
      
        # Initialize heights array for histogram representation
        num_cols = len(matrix[0])
        heights = [0] * num_cols
        max_area = 0
      
        # Process each row
        for row in matrix:
            # Update heights: increment if '1', reset to 0 if '0'
            for col_idx, value in enumerate(row):
                if value == "1":
                    heights[col_idx] += 1
                else:
                    heights[col_idx] = 0
          
            # Calculate max rectangle area for current histogram
            max_area = max(max_area, self.largestRectangleArea(heights))
      
        return max_area

    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        Find the largest rectangle area in a histogram.
      
        Uses monotonic stack to find the nearest smaller element on both left and right
        for each bar, then calculates the maximum rectangle area.
      
        Args:
            heights: List of bar heights in the histogram
          
        Returns:
            Area of the largest rectangle in the histogram
        """
        n = len(heights)
        if n == 0:
            return 0
      
        # Arrays to store indices of nearest smaller elements
        left_boundaries = [-1] * n  # Index of nearest smaller element on the left
        right_boundaries = [n] * n   # Index of nearest smaller element on the right
      
        # Find left boundaries using monotonic increasing stack
        stack = []
        for i, height in enumerate(heights):
            # Pop elements >= current height
            while stack and heights[stack[-1]] >= height:
                stack.pop()
          
            # If stack not empty, top element is the nearest smaller on left
            if stack:
                left_boundaries[i] = stack[-1]
          
            stack.append(i)
      
        # Find right boundaries using monotonic increasing stack (traverse right to left)
        stack = []
        for i in range(n - 1, -1, -1):
            height = heights[i]
          
            # Pop elements >= current height
            while stack and heights[stack[-1]] >= height:
                stack.pop()
          
            # If stack not empty, top element is the nearest smaller on right
            if stack:
                right_boundaries[i] = stack[-1]
          
            stack.append(i)
      
        # Calculate maximum rectangle area
        # For each bar, the rectangle extends from (left_boundary + 1) to (right_boundary - 1)
        max_area = max(
            height * (right_boundaries[i] - left_boundaries[i] - 1) 
            for i, height in enumerate(heights)
        )
      
        return max_area
        