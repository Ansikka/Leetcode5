class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # Create a 2D array to represent the champagne tower
        # Each cell stores the amount of champagne in that glass
        tower = [[0.0] * 101 for _ in range(101)]
      
        # Pour all champagne into the top glass
        tower[0][0] = float(poured)
      
        # Simulate the overflow process row by row
        for row in range(query_row + 1):
            for col in range(row + 1):
                # If current glass has more than 1 cup of champagne
                if tower[row][col] > 1.0:
                    # Calculate the overflow amount (everything above 1 cup)
                    overflow = tower[row][col] - 1.0
                  
                    # Keep only 1 cup in the current glass
                    tower[row][col] = 1.0
                  
                    # Split the overflow equally between the two glasses below
                    # Left child glass gets half of the overflow
                    tower[row + 1][col] += overflow / 2.0
                  
                    # Right child glass gets half of the overflow
                    tower[row + 1][col + 1] += overflow / 2.0
      
        # Return the amount in the queried glass (max 1.0)
        return min(1.0, tower[query_row][query_glass])