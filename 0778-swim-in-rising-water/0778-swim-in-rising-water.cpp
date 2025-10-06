class Solution {
public:
    vector<int> parent;  // Union-Find parent array
  
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
      
        // Initialize Union-Find structure
        // Each cell is initially its own parent
        parent.resize(n * n);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
      
        // Create a mapping from elevation value to its position
        // heightToIndex[h] stores the flattened index of cell with elevation h
        vector<int> heightToIndex(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                heightToIndex[grid[i][j]] = i * n + j;
            }
        }
      
        // Direction vectors for exploring 4 adjacent cells (up, right, down, left)
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        // Process cells in increasing order of elevation (time)
        for (int time = 0; time < n * n; ++time) {
            // Get the position of the cell with elevation equal to current time
            int currentIndex = heightToIndex[time];
            int row = currentIndex / n;
            int col = currentIndex % n;
          
            // Check all 4 adjacent cells
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
              
                // If adjacent cell is valid and has elevation <= current time,
                // union it with current cell
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                    grid[newRow][newCol] <= time) {
                    int adjacentIndex = newRow * n + newCol;
                    parent[find(adjacentIndex)] = find(currentIndex);
                }
              
                // Check if start (0,0) and end (n-1,n-1) are connected
                if (find(0) == find(n * n - 1)) {
                    return time;
                }
            }
        }
      
        return -1;  // Should never reach here for valid input
    }
  
private:
    // Find operation with path compression for Union-Find
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
};
