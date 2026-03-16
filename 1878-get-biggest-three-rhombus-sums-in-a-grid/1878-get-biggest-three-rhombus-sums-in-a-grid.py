class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        # Get grid dimensions
        rows, cols = len(grid), len(grid[0])
      
        # Create prefix sum arrays for diagonal directions
        # diagonal_sum_down_right[i][j] stores cumulative sum along down-right diagonal ending at (i,j)
        diagonal_sum_down_right = [[0] * (cols + 2) for _ in range(rows + 1)]
        # diagonal_sum_down_left[i][j] stores cumulative sum along down-left diagonal ending at (i,j)
        diagonal_sum_down_left = [[0] * (cols + 2) for _ in range(rows + 1)]
      
        # Build prefix sums for both diagonal directions
        # Using 1-indexed to simplify boundary handling
        for i, row in enumerate(grid, 1):
            for j, value in enumerate(row, 1):
                # Down-right diagonal: moving from top-left to bottom-right
                diagonal_sum_down_right[i][j] = diagonal_sum_down_right[i - 1][j - 1] + value
                # Down-left diagonal: moving from top-right to bottom-left
                diagonal_sum_down_left[i][j] = diagonal_sum_down_left[i - 1][j + 1] + value
      
        # Use SortedSet to maintain unique rhombus sums in sorted order
        unique_sums = SortedSet()
      
        # Check all possible rhombus centers
        for i, row in enumerate(grid, 1):
            for j, center_value in enumerate(row, 1):
                # Calculate maximum possible rhombus radius from this center
                # Limited by distance to grid boundaries
                max_radius = min(i - 1, rows - i, j - 1, cols - j)
              
                # Add single cell (radius 0 rhombus)
                unique_sums.add(center_value)
              
                # Check all possible rhombus sizes with center at (i, j)
                for radius in range(1, max_radius + 1):
                    # Calculate sum of rhombus edges using prefix sums
                    # Top-right edge: from center going up-right then down-right
                    top_right_edge = diagonal_sum_down_right[i + radius][j] - diagonal_sum_down_right[i][j - radius]
                    # Bottom-right edge: from center going right then down-left
                    bottom_right_edge = diagonal_sum_down_right[i][j + radius] - diagonal_sum_down_right[i - radius][j]
                    # Top-left edge: from center going left then up-right
                    top_left_edge = diagonal_sum_down_left[i][j - radius] - diagonal_sum_down_left[i - radius][j]
                    # Bottom-left edge: from center going down then left
                    bottom_left_edge = diagonal_sum_down_left[i + radius][j] - diagonal_sum_down_left[i][j + radius]
                  
                    # Calculate total rhombus sum
                    # Need to adjust for corner vertices that are counted twice
                    rhombus_sum = (top_right_edge + bottom_right_edge + top_left_edge + bottom_left_edge 
                                  - grid[i + radius - 1][j - 1] + grid[i - radius - 1][j - 1])
                  
                    unique_sums.add(rhombus_sum)
              
                # Keep only the 3 largest values
                while len(unique_sums) > 3:
                    unique_sums.remove(unique_sums[0])  # Remove smallest
      
        # Return the 3 largest values in descending order
        return list(unique_sums)[::-1]
