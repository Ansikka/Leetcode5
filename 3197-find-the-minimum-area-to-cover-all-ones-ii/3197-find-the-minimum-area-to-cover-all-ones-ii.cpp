class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
             int m = grid.size();                // Number of rows in the grid
        int n = grid[0].size();             // Number of columns in the grid
        int ans = m * n;                    // Initialize the minimum sum to the maximum possible value
        int inf = INT_MAX / 4;              // Define a large number to handle integer operations and avoid overflow

        // Lambda function to calculate the sum of a subgrid
        auto f = [&](int i1, int j1, int i2, int j2) {
            int x1 = inf, y1 = inf;         // Initialize the top-left corner of the subgrid
            int x2 = -inf, y2 = -inf;       // Initialize the bottom-right corner of the subgrid

            // Traverse the subgrid to find the bounding box of all '1's
            for (int i = i1; i <= i2; i++) {
                for (int j = j1; j <= j2; j++) {
                    if (grid[i][j] == 1) {
                        x1 = std::min(x1, i);  // Update the x-coordinate of the top-left corner
                        y1 = std::min(y1, j);  // Update the y-coordinate of the top-left corner
                        x2 = std::max(x2, i);  // Update the x-coordinate of the bottom-right corner
                        y2 = std::max(y2, j);  // Update the y-coordinate of the bottom-right corner
                    }
                }
            }

            // If no '1' is found in the subgrid, return infinity to ignore this partition
            return x1 > x2 || y1 > y2 ? inf : (x2 - x1 + 1) * (y2 - y1 + 1);
        };

        // Try partitioning the grid into 3 horizontal sections and calculate their sums
        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = std::min(ans, f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1));
            }
        }

        // Try partitioning the grid into 3 vertical sections and calculate their sums
        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = std::min(ans, f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1));
            }
        }

        // Try different combinations of horizontal and vertical cuts
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = std::min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
                ans = std::min(ans, f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1));
                ans = std::min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
                ans = std::min(ans, f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1));
            }
        }

        return ans;  // Return the minimum sum of the partitions
    }
};