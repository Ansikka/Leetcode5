class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         vector<vector<bool>> rows(9, vector<bool>(9, false));
        // columns[j][num] = true if number (num+1) exists in column j
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        // subBoxes[k][num] = true if number (num+1) exists in sub-box k
        vector<vector<bool>> subBoxes(9, vector<bool>(9, false));
      
        // Iterate through each cell in the 9x9 board
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char currentCell = board[row][col];
              
                // Skip empty cells
                if (currentCell == '.') {
                    continue;
                }
              
                // Convert character to 0-indexed number (e.g., '1' -> 0, '9' -> 8)
                int digitIndex = currentCell - '0' - 1;
              
              
                int subBoxIndex = (row / 3) * 3 + (col / 3);
              
                
                if (rows[row][digitIndex] || 
                    columns[col][digitIndex] || 
                    subBoxes[subBoxIndex][digitIndex]) {
                    return false;  
                }
              
               
                rows[row][digitIndex] = true;
                columns[col][digitIndex] = true;
                subBoxes[subBoxIndex][digitIndex] = true;
            }
        }
      
      
        return true;
    }
};