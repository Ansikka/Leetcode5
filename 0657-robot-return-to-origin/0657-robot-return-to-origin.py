class Solution:
    def judgeCircle(self, moves: str) -> bool:
        """
        Determines if a sequence of moves returns to the origin (0, 0).
      
        Args:
            moves: A string containing move commands ('U', 'D', 'L', 'R')
      
        Returns:
            True if the final position is (0, 0), False otherwise
        """
        # Initialize coordinates at origin
        x_position = 0
        y_position = 0
      
        # Process each move command
        for move in moves:
            if move == "U":  # Move up
                y_position += 1
            elif move == "D":  # Move down
                y_position -= 1
            elif move == "L":  # Move left
                x_position -= 1
            elif move == "R":  # Move right
                x_position += 1
      
        # Check if we returned to origin
        return x_position == 0 and y_position == 0