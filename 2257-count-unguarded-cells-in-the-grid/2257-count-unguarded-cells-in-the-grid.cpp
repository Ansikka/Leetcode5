class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       
        // Create a grid to track cell states:
        // 0 = unguarded, 1 = guarded (visible by guard), 2 = occupied (guard or wall)
        vector<vector<int>> grid(m, vector<int>(n, 0));
      
        // Mark all guard positions as occupied
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
      
        // Mark all wall positions as occupied
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
      
        // Direction vectors for moving up, right, down, left
        // Using pairs: (dx[i], dy[i]) represents one direction
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
      
        // For each guard, mark all cells they can see in four directions
        for (const auto& guard : guards) {
            // Check all four directions
            for (int dir = 0; dir < 4; ++dir) {
                int currentRow = guard[0];
                int currentCol = guard[1];
                int rowDelta = dx[dir];
                int colDelta = dy[dir];
              
                // Continue in current direction until hitting boundary or obstacle
                while (currentRow + rowDelta >= 0 && 
                       currentRow + rowDelta < m && 
                       currentCol + colDelta >= 0 && 
                       currentCol + colDelta < n && 
                       grid[currentRow + rowDelta][currentCol + colDelta] < 2) {
                  
                    // Move to next cell in current direction
                    currentRow += rowDelta;
                    currentCol += colDelta;
                  
                    // Mark this cell as guarded
                    grid[currentRow][currentCol] = 1;
                }
            }
        }
      
        // Count all unguarded cells (cells with value 0)
        int unguardedCount = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    unguardedCount++;
                }
            }
        }
      
        return unguardedCount; 
    }
};