class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
         using HeightPosition = tuple<int, int, int>;
        priority_queue<HeightPosition, vector<HeightPosition>, greater<HeightPosition>> minHeap;
      
        int rows = heightMap.size();
        int cols = heightMap[0].size();
      
        // Track visited cells to avoid revisiting
        bool visited[rows][cols];
        memset(visited, 0, sizeof(visited));
      
        // Add all boundary cells to the heap as starting points
        // Water can flow out from boundaries, so they determine water levels
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                    minHeap.emplace(heightMap[row][col], row, col);
                    visited[row][col] = true;
                }
            }
        }
      
        int totalWater = 0;
      
        // Direction vectors for moving up, right, down, left
        int directions[5] = {-1, 0, 1, 0, -1};
      
        // Process cells from lowest to highest height
        while (!minHeap.empty()) {
            // Get the cell with minimum height from the boundary
            auto [currentHeight, currentRow, currentCol] = minHeap.top();
            minHeap.pop();
          
            // Check all 4 adjacent cells
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = currentRow + directions[dir];
                int nextCol = currentCol + directions[dir + 1];
              
                // If the adjacent cell is valid and not visited
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    !visited[nextRow][nextCol]) {
                  
                    // Water trapped = difference between water level and ground height
                    // Water level is determined by the minimum boundary height encountered
                    totalWater += max(0, currentHeight - heightMap[nextRow][nextCol]);
                  
                    visited[nextRow][nextCol] = true;
                  
                    // Add the cell to heap with updated water level
                    // The water level for this cell becomes the max of its height and current water level
                    minHeap.emplace(max(heightMap[nextRow][nextCol], currentHeight), nextRow, nextCol);
                }
            }
        }
      
        return totalWater;
    }
};