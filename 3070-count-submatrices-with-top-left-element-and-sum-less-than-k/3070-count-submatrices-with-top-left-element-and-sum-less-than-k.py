class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        # Get dimensions of the grid
        rows = len(grid)
        cols = len(grid[0])
      
        # Create prefix sum array with padding for easier calculation
        # prefix_sum[i][j] represents sum of all elements in submatrix from (0,0) to (i-1,j-1)
        prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
      
        # Counter for valid submatrices
        count = 0
      
        # Build prefix sum array and count valid submatrices
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                # Calculate prefix sum using inclusion-exclusion principle
                # Sum = sum_above + sum_left - sum_diagonal + current_element
                prefix_sum[i][j] = (prefix_sum[i - 1][j] + 
                                   prefix_sum[i][j - 1] - 
                                   prefix_sum[i - 1][j - 1] + 
                                   grid[i - 1][j - 1])
              
                # Check if submatrix from (0,0) to current position has sum <= k
                if prefix_sum[i][j] <= k:
                    count += 1
      
        return count