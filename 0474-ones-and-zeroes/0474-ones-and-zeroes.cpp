class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
            int numStrings = strs.size();
      
        // dp[i][j][k] represents the maximum number of strings that can be formed
        // using the first i strings with at most j zeros and k ones
        int dp[numStrings + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
      
        // Iterate through each string
        for (int i = 1; i <= numStrings; ++i) {
            // Count zeros and ones in the current string
            auto [zeros, ones] = countZerosAndOnes(strs[i - 1]);
          
            // Iterate through all possible limits of zeros
            for (int j = 0; j <= m; ++j) {
                // Iterate through all possible limits of ones
                for (int k = 0; k <= n; ++k) {
                    // Option 1: Don't include the current string
                    dp[i][j][k] = dp[i - 1][j][k];
                  
                    // Option 2: Include the current string if we have enough zeros and ones
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
      
        // Return the maximum number of strings that can be formed with m zeros and n ones
        return dp[numStrings][m][n];
    }

private:
    // Helper function to count the number of zeros and ones in a string
    pair<int, int> countZerosAndOnes(string& str) {
        int zeroCount = count_if(str.begin(), str.end(), [](char c) { return c == '0'; });
        int oneCount = str.size() - zeroCount;
        return {zeroCount, oneCount};
    }
};