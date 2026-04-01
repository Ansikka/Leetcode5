class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        """
        Simulates robot collisions on a line and returns surviving robots' healths.
      
        Args:
            positions: List of initial positions of robots
            healths: List of initial health values of robots
            directions: String where each character is 'L' or 'R' indicating direction
          
        Returns:
            List of health values for surviving robots in their original order
        """
        n = len(positions)
        # Create indices to track original robot positions
        indices = list(range(n))
        # Stack to store indices of robots moving right
        stack = []
      
        # Sort indices by robot positions to process collisions from left to right
        indices.sort(key=lambda i: positions[i])
      
        # Process each robot in position order
        for current_index in indices:
            if directions[current_index] == "R":
                # Robot moving right: add to stack for potential future collisions
                stack.append(current_index)
            else:
                # Robot moving left: check for collisions with robots moving right
                while stack and healths[current_index] > 0:
                    # Get the rightmost robot moving right
                    top_index = stack.pop()
                  
                    if healths[top_index] > healths[current_index]:
                        # Right-moving robot wins: reduce its health by 1
                        healths[top_index] -= 1
                        healths[current_index] = 0
                        # Put winner back on stack
                        stack.append(top_index)
                    elif healths[top_index] < healths[current_index]:
                        # Left-moving robot wins: reduce its health by 1
                        healths[current_index] -= 1
                        healths[top_index] = 0
                        # Continue checking for more collisions
                    else:
                        # Both robots have equal health: both are destroyed
                        healths[current_index] = 0
                        healths[top_index] = 0
      
        # Return health values of surviving robots (health > 0) in original order
        result = [health for health in healths if health > 0]
        return result