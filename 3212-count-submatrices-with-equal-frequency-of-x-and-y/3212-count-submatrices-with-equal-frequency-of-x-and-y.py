class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        # Get grid dimensions
        rows, cols = len(grid), len(grid[0])
      
        # Initialize prefix sum array with padding
        # prefix_sum[i][j][0] stores count of first type characters (e.g., 'Y')
        # prefix_sum[i][j][1] stores count of second type characters (e.g., 'X')
        prefix_sum = [[[0] * 2 for _ in range(cols + 1)] for _ in range(rows + 1)]
      
        result_count = 0
      
        # Iterate through each cell of the grid (1-indexed for easier prefix sum calculation)
        for row_idx, row_data in enumerate(grid, 1):
            for col_idx, cell_value in enumerate(row_data, 1):
                # Calculate prefix sum for both character types using inclusion-exclusion principle
                # Copy counts from top and left cells, subtract overlap
                prefix_sum[row_idx][col_idx][0] = (prefix_sum[row_idx - 1][col_idx][0] + 
                                                   prefix_sum[row_idx][col_idx - 1][0] - 
                                                   prefix_sum[row_idx - 1][col_idx - 1][0])
              
                prefix_sum[row_idx][col_idx][1] = (prefix_sum[row_idx - 1][col_idx][1] + 
                                                   prefix_sum[row_idx][col_idx - 1][1] - 
                                                   prefix_sum[row_idx - 1][col_idx - 1][1])
              
                # If current cell is not empty, increment the appropriate counter
                if cell_value != ".":
                    # Use ASCII value's least significant bit to determine character type
                    # 'X' (ASCII 88) & 1 = 0, 'Y' (ASCII 89) & 1 = 1
                    character_type = ord(cell_value) & 1
                    prefix_sum[row_idx][col_idx][character_type] += 1
              
                # Check if submatrix from (0,0) to current position is valid
                # Valid means: has at least one 'X' and equal counts of both types
                if (prefix_sum[row_idx][col_idx][0] > 0 and 
                    prefix_sum[row_idx][col_idx][0] == prefix_sum[row_idx][col_idx][1]):
                    result_count += 1
      
        return result_count