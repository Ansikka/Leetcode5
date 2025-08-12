class Solution {
public:
    int numberOfWays(int n, int x) {
         const int MOD = 1e9 + 7;                                // Modular constant for large numbers
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0)); // DP table to store intermediate results

        dp[0][0] = 1;                                          // Base case: one way to sum up 0 using 0 elements
        for (int i = 1; i <= n; ++i) {                         // Loop through numbers from 1 to n
            long long powerOfI = (long long)std::pow(i, x);    // Calculate the i-th power of x
            for (int j = 0; j <= n; ++j) {                     // Loop through all the possible sums from 0 to n
                dp[i][j] = dp[i - 1][j];                       // Without the current number i, ways are from previous
                if (powerOfI <= j) {
                    // If current power of i fits into sum j, add ways where i contributes to sum j
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - powerOfI]) % MOD;
                }
            }
        }
        return dp[n][n];
    }
};