class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        # Get grid dimensions
        rows, cols = len(grid), len(grid[0])
      
        # Track visited cells
        visited = [[False] * cols for _ in range(rows)]
      
        # Direction vectors for moving up, right, down, left
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
      
        # Check each cell as a potential starting point
        for start_row in range(rows):
            for start_col in range(cols):
                # Skip if already visited
                if visited[start_row][start_col]:
                    continue
              
                # Mark starting cell as visited
                visited[start_row][start_col] = True
              
                # Initialize stack for DFS: (current_row, current_col, parent_row, parent_col)
                # Parent is used to avoid going back to the cell we came from
                stack = [(start_row, start_col, -1, -1)]
              
                # Perform DFS to find cycle
                while stack:
                    curr_row, curr_col, parent_row, parent_col = stack.pop()
                  
                    # Check all four adjacent cells
                    for delta_row, delta_col in directions:
                        next_row = curr_row + delta_row
                        next_col = curr_col + delta_col
                      
                        # Check if next cell is within bounds
                        if 0 <= next_row < rows and 0 <= next_col < cols:
                            # Skip if different value or if it's the parent cell
                            if (grid[next_row][next_col] != grid[start_row][start_col] or 
                                (next_row == parent_row and next_col == parent_col)):
                                continue
                          
                            # If we've visited this cell before in current component, we found a cycle
                            if visited[next_row][next_col]:
                                return True
                          
                            # Mark as visited and add to stack
                            visited[next_row][next_col] = True
                            stack.append((next_row, next_col, curr_row, curr_col))
      
        # No cycle found
        return False