class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        """
        Find the size of the largest magic square that can be found in the grid.
        A magic square is a square where all rows, columns, and both diagonals sum to the same value.
        """
        rows, cols = len(grid), len(grid[0])
      
        # Build prefix sum arrays for efficient range sum queries
        # row_prefix_sum[i][j] = sum of elements from grid[i-1][0] to grid[i-1][j-1]
        row_prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
        # col_prefix_sum[i][j] = sum of elements from grid[0][j-1] to grid[i-1][j-1]
        col_prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
      
        # Populate prefix sum arrays
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                row_prefix_sum[i][j] = row_prefix_sum[i][j - 1] + grid[i - 1][j - 1]
                col_prefix_sum[i][j] = col_prefix_sum[i - 1][j] + grid[i - 1][j - 1]

        def is_magic_square(top_row: int, left_col: int, bottom_row: int, right_col: int) -> bool:
            """
            Check if the square defined by corners (top_row, left_col) and (bottom_row, right_col)
            is a magic square where all rows, columns, and diagonals have the same sum.
            """
            # Calculate the target sum using the first row
            target_sum = row_prefix_sum[top_row + 1][right_col + 1] - row_prefix_sum[top_row + 1][left_col]
          
            # Check all rows have the same sum
            for row in range(top_row + 1, bottom_row + 1):
                row_sum = row_prefix_sum[row + 1][right_col + 1] - row_prefix_sum[row + 1][left_col]
                if row_sum != target_sum:
                    return False
          
            # Check all columns have the same sum
            for col in range(left_col, right_col + 1):
                col_sum = col_prefix_sum[bottom_row + 1][col + 1] - col_prefix_sum[top_row][col + 1]
                if col_sum != target_sum:
                    return False
          
            # Check main diagonal (top-left to bottom-right)
            main_diagonal_sum = 0
            row, col = top_row, left_col
            while row <= bottom_row:
                main_diagonal_sum += grid[row][col]
                row += 1
                col += 1
            if main_diagonal_sum != target_sum:
                return False
          
            # Check anti-diagonal (top-right to bottom-left)
            anti_diagonal_sum = 0
            row, col = top_row, right_col
            while row <= bottom_row:
                anti_diagonal_sum += grid[row][col]
                row += 1
                col -= 1
            if anti_diagonal_sum != target_sum:
                return False
          
            return True

        # Try square sizes from largest to smallest
        for square_size in range(min(rows, cols), 1, -1):
            # Try all possible positions for a square of this size
            for start_row in range(rows - square_size + 1):
                for start_col in range(cols - square_size + 1):
                    end_row = start_row + square_size - 1
                    end_col = start_col + square_size - 1
                  
                    if is_magic_square(start_row, start_col, end_row, end_col):
                        return square_size
      
        # Every 1x1 square is a magic square
        return 1