class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
      
        // Sort diagonals starting from the second last row to the first row
        for (int startRow = n - 2; startRow >= 0; --startRow) {
            int i = startRow, j = 0;
            std::vector<int> diagonalElements;
          
            // Collect elements along the diagonal from (startRow, 0)
            while (i < n && j < n) {
                diagonalElements.push_back(grid[i][j]);
                i++;
                j++;
            }
          
            // Sort the collected diagonal elements
            std::sort(diagonalElements.begin(), diagonalElements.end());
          
            // Place sorted elements back into the grid
            for (int element : diagonalElements) {
                i--;
                j--;
                grid[i][j] = element;
            }
        }
      
        // Sort diagonals starting from the second column to the last column
        for (int startCol = n - 2; startCol > 0; --startCol) {
            int i = startCol, j = n - 1;
            std::vector<int> diagonalElements;
          
            // Collect elements along the diagonal from (startCol, lastCol)
            while (i >= 0 && j >= 0) {
                diagonalElements.push_back(grid[i][j]);
                i--;
                j--;
            }
          
            // Sort the collected diagonal elements
            std::sort(diagonalElements.begin(), diagonalElements.end());
          
            // Place sorted elements back into the grid
            for (int element : diagonalElements) {
                i++;
                j++;
                grid[i][j] = element;
            }
        }
      
        return grid;
    }
};