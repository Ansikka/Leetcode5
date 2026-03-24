class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        # Get dimensions of the input grid
        rows, cols = len(grid), len(grid[0])
      
        # Initialize result matrix with zeros
        result = [[0] * cols for _ in range(rows)]
      
        # Modulo value for all calculations
        MOD = 12345
      
        # First pass: Calculate suffix products (from bottom-right to top-left)
        # For each cell, store the product of all cells that come after it
        suffix_product = 1
        for row in range(rows - 1, -1, -1):
            for col in range(cols - 1, -1, -1):
                # Store current suffix product in result matrix
                result[row][col] = suffix_product
                # Update suffix product for next iteration
                suffix_product = (suffix_product * grid[row][col]) % MOD
      
        # Second pass: Multiply by prefix products (from top-left to bottom-right)
        # For each cell, multiply its suffix product by the prefix product
        prefix_product = 1
        for row in range(rows):
            for col in range(cols):
                # Multiply suffix product by prefix product to get final result
                result[row][col] = (result[row][col] * prefix_product) % MOD
                # Update prefix product for next iteration
                prefix_product = (prefix_product * grid[row][col]) % MOD
      
        return result
