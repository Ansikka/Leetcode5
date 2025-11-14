class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
               vector<vector<int>> matrix(n, vector<int>(n, 0));
      
        // Apply difference array technique in 2D
        // Mark the boundaries of each query rectangle
        for (const auto& query : queries) {
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
          
            // Mark the top-left corner with +1
            matrix[row1][col1]++;
          
            // Mark the row after bottom boundary with -1
            if (row2 + 1 < n) {
                matrix[row2 + 1][col1]--;
            }
          
            // Mark the column after right boundary with -1
            if (col2 + 1 < n) {
                matrix[row1][col2 + 1]--;
            }
          
            // Mark the diagonal corner (row2+1, col2+1) with +1
            // This compensates for the double subtraction
            if (row2 + 1 < n && col2 + 1 < n) {
                matrix[row2 + 1][col2 + 1]++;
            }
        }
      
        // Compute 2D prefix sum to get the final result
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Add value from the cell above
                if (i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
              
                // Add value from the cell to the left
                if (j > 0) {
                    matrix[i][j] += matrix[i][j - 1];
                }
              
                // Subtract the diagonal cell to avoid double counting
                if (i > 0 && j > 0) {
                    matrix[i][j] -= matrix[i - 1][j - 1];
                }
            }
        }
      
        return matrix;
    }
};