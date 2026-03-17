class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        # Build consecutive ones height for each column
        # For each cell, if it's 1, accumulate the height from the cell above
        for row in range(1, len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] == 1:
                    # Add the consecutive ones from the row above
                    matrix[row][col] = matrix[row - 1][col] + 1
      
        max_area = 0
      
        # For each row, find the maximum rectangle area
        for row in matrix:
            # Sort heights in descending order to form valid rectangles
            # After sorting, position j can form a rectangle with width j
            row.sort(reverse=True)
          
            # Calculate area for each possible width
            # Width j (1-indexed) with height row[j-1] forms a rectangle
            for width, height in enumerate(row, start=1):
                current_area = width * height
                max_area = max(max_area, current_area)
      
        return max_area