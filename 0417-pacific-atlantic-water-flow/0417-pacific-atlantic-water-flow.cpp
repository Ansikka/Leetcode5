typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> heightsGrid;
    int rows;
    int cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Initialize dimensions and store the heights grid
        rows = heights.size();
        cols = heights[0].size();
        this->heightsGrid = heights;
      
        // Queues for BFS from Pacific and Atlantic oceans
        queue<pii> pacificQueue;
        queue<pii> atlanticQueue;
      
        // Sets to track visited cells for each ocean (using flattened indices)
        unordered_set<int> pacificVisited;
        unordered_set<int> atlanticVisited;
      
        // Initialize starting points for both oceans
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Pacific Ocean: top row and left column
                if (row == 0 || col == 0) {
                    int flatIndex = row * cols + col;
                    pacificVisited.insert(flatIndex);
                    pacificQueue.emplace(row, col);
                }
                // Atlantic Ocean: bottom row and right column
                if (row == rows - 1 || col == cols - 1) {
                    int flatIndex = row * cols + col;
                    atlanticVisited.insert(flatIndex);
                    atlanticQueue.emplace(row, col);
                }
            }
        }
      
        // Perform BFS from both oceans to find all reachable cells
        bfs(pacificQueue, pacificVisited);
        bfs(atlanticQueue, atlanticVisited);
      
        // Find cells that can reach both oceans
        vector<vector<int>> result;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int flatIndex = row * cols + col;
                // If cell is reachable from both oceans, add to result
                if (pacificVisited.count(flatIndex) && atlanticVisited.count(flatIndex)) {
                    result.push_back({row, col});
                }
            }
        }
      
        return result;
    }

    void bfs(queue<pii>& bfsQueue, unordered_set<int>& visited) {
        // Direction vectors for up, right, down, left movement
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        while (!bfsQueue.empty()) {
            // Process all cells at current BFS level
            int levelSize = bfsQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                auto currentCell = bfsQueue.front();
                bfsQueue.pop();
              
                // Check all 4 adjacent cells
                for (int dir = 0; dir < 4; ++dir) {
                    int nextRow = currentCell.first + directions[dir];
                    int nextCol = currentCell.second + directions[dir + 1];
                    int flatIndex = nextRow * cols + nextCol;
                  
                    // Check if next cell is valid, unvisited, and water can flow from it to current cell
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        !visited.count(flatIndex) && 
                        heightsGrid[nextRow][nextCol] >= heightsGrid[currentCell.first][currentCell.second]) {
                      
                        visited.insert(flatIndex);
                        bfsQueue.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
};
