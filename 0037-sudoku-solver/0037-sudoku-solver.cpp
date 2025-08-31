class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         bool rowUsed[9][9] = {false};
        // Track which numbers (0-8) are used in each column
        bool colUsed[9][9] = {false};
        // Track which numbers (0-8) are used in each 3x3 block
        bool blockUsed[3][3][9] = {false};
      
        // Flag to indicate when solution is found
        bool solutionFound = false;
      
        // Store positions of all empty cells
        vector<pair<int, int>> emptyCells;
      
        // Initialize the tracking arrays and collect empty cells
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    // Add empty cell position to list
                    emptyCells.push_back({row, col});
                } else {
                    // Mark existing number as used
                    int digit = board[row][col] - '1';  // Convert char to 0-based index
                    rowUsed[row][digit] = true;
                    colUsed[col][digit] = true;
                    blockUsed[row / 3][col / 3][digit] = true;
                }
            }
        }
      
        // Recursive backtracking function to fill empty cells
        function<void(int)> backtrack = [&](int cellIndex) {
            // Base case: all empty cells have been filled
            if (cellIndex == emptyCells.size()) {
                solutionFound = true;
                return;
            }
          
            // Get current empty cell position
            int currentRow = emptyCells[cellIndex].first;
            int currentCol = emptyCells[cellIndex].second;
            int blockRow = currentRow / 3;
            int blockCol = currentCol / 3;
          
            // Try placing digits 1-9 (represented as 0-8 internally)
            for (int digit = 0; digit < 9; ++digit) {
                // Check if digit can be placed at current position
                if (!rowUsed[currentRow][digit] && 
                    !colUsed[currentCol][digit] && 
                    !blockUsed[blockRow][blockCol][digit]) {
                  
                    // Place the digit
                    rowUsed[currentRow][digit] = true;
                    colUsed[currentCol][digit] = true;
                    blockUsed[blockRow][blockCol][digit] = true;
                    board[currentRow][currentCol] = digit + '1';  // Convert to char
                  
                    // Recursively fill next empty cell
                    backtrack(cellIndex + 1);
                  
                    // If solution found, stop backtracking
                    if (solutionFound) {
                        return;
                    }
                  
                    // Backtrack: remove the digit
                    rowUsed[currentRow][digit] = false;
                    colUsed[currentCol][digit] = false;
                    blockUsed[blockRow][blockCol][digit] = false;
                }
            }
        };
      
        // Start solving from the first empty cell
        backtrack(0);
    }
};