class Solution {
public:
  

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      
        // Dynamic programming array to store minimum path sums
        // Size is n+1 to avoid boundary checks, with the extra element initialized to 0
        vector<int> dp(n + 1, 0);
      
        // Process the triangle from bottom to top
        for (int row = n - 1; row >= 0; --row) {
            // For each element in the current row, update the minimum path sum
            for (int col = 0; col <= row; ++col) {
                // Choose the minimum of the two adjacent elements from the row below
                // and add the current element's value
                dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
            }
        }
      
        // The minimum path sum from top to bottom is stored at dp[0]
        return dp[0];
    }
};