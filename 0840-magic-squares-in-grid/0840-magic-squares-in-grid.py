class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def is_magic_square(row: int, col: int) -> int:
            """
            Check if a 3x3 subgrid starting at (row, col) is a magic square.
            A magic square contains all numbers 1-9 exactly once and has equal sums
            for all rows, columns, and diagonals.
          
            Args:
                row: Starting row index of the 3x3 subgrid
                col: Starting column index of the 3x3 subgrid
              
            Returns:
                1 if it's a magic square, 0 otherwise
            """
            # Check if 3x3 subgrid is within bounds
            if row + 3 > rows or col + 3 > cols:
                return 0
          
            # Track unique numbers and sums
            unique_numbers = set()
            row_sums = [0] * 3
            col_sums = [0] * 3
            main_diagonal_sum = 0
            anti_diagonal_sum = 0
          
            # Iterate through the 3x3 subgrid
            for i in range(row, row + 3):
                for j in range(col, col + 3):
                    value = grid[i][j]
                  
                    # Check if value is in valid range [1, 9]
                    if value < 1 or value > 9:
                        return 0
                  
                    # Add to set of unique numbers
                    unique_numbers.add(value)
                  
                    # Calculate relative position within 3x3 subgrid
                    relative_row = i - row
                    relative_col = j - col
                  
                    # Update row and column sums
                    row_sums[relative_row] += value
                    col_sums[relative_col] += value
                  
                    # Update main diagonal sum (top-left to bottom-right)
                    if relative_row == relative_col:
                        main_diagonal_sum += value
                  
                    # Update anti-diagonal sum (top-right to bottom-left)
                    if relative_row == 2 - relative_col:
                        anti_diagonal_sum += value
          
            # Check if all numbers 1-9 are present exactly once
            if len(unique_numbers) != 9:
                return 0
          
            # Check if both diagonals have the same sum
            if main_diagonal_sum != anti_diagonal_sum:
                return 0
          
            # Check if all rows have the same sum as the main diagonal
            if any(row_sum != main_diagonal_sum for row_sum in row_sums):
                return 0
          
            # Check if all columns have the same sum as the main diagonal
            if any(col_sum != main_diagonal_sum for col_sum in col_sums):
                return 0
          
            return 1
      
        # Get grid dimensions
        rows, cols = len(grid), len(grid[0])
      
        # Count all magic squares by checking each possible 3x3 subgrid
        return sum(is_magic_square(i, j) for i in range(rows) for j in range(cols))