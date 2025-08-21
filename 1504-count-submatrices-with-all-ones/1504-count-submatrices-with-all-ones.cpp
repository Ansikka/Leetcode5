class Solution {
public:
  

      int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size(); // dimensions of the matrix
        vector<vector<int>> width(rows, vector<int>(cols, 0)); // 2D vector to track the width of '1's ending at mat[i][j]

        // Pre-calculate the width of the continuous '1's in each row, left to right
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 1) {
                    width[row][col] = col == 0 ? 1 : 1 + width[row][col - 1];
                }
                // if mat[row][col] is 0, width[row][col] stays 0, which was set initially
            }
        }

        int totalCount = 0; // count of all possible submatrices

        // Main logic to find the total number of submatrices with 1
        for (int topRow = 0; topRow < rows; ++topRow) {
            for (int col = 0; col < cols; ++col) {
                int minWidth = INT_MAX; // set minWidth to maximum possible value initially
                // Evaluate bottom-up for each submatrix
                for (int bottomRow = topRow; bottomRow >= 0 && minWidth > 0; --bottomRow) {
                    minWidth = min(minWidth, width[bottomRow][col]); // find minimal width of '1's column-wise
                    totalCount += minWidth; // Add the minimum width to the totalCount
                }
            }
        } 

        return totalCount; 
    }
};