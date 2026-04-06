class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Direction vectors: North(0,1), East(1,0), South(0,-1), West(-1,0)
        # Stored as (dx1, dy1, dx2, dy2, dx3, dy3, dx4, dy4) in flattened array
        directions = (0, 1, 0, -1, 0)
      
        # Convert obstacles list to set for O(1) lookup
        obstacle_set = {(x, y) for x, y in obstacles}
      
        # Initialize maximum distance and current direction index
        max_distance_squared = 0
        direction_index = 0  # 0: North, 1: East, 2: South, 3: West
      
        # Starting position
        current_x = 0
        current_y = 0
      
        # Process each command
        for command in commands:
            if command == -2:
                # Turn left: counterclockwise rotation (equivalent to +3 mod 4)
                direction_index = (direction_index + 3) % 4
            elif command == -1:
                # Turn right: clockwise rotation
                direction_index = (direction_index + 1) % 4
            else:
                # Move forward 'command' steps
                for _ in range(command):
                    # Calculate next position based on current direction
                    next_x = current_x + directions[direction_index]
                    next_y = current_y + directions[direction_index + 1]
                  
                    # Check if next position is an obstacle
                    if (next_x, next_y) in obstacle_set:
                        break
                  
                    # Update current position
                    current_x = next_x
                    current_y = next_y
                  
                    # Update maximum Euclidean distance squared from origin
                    max_distance_squared = max(max_distance_squared, 
                                              current_x * current_x + current_y * current_y)
      
        return max_distance_squared