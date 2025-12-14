class Solution {
public:
    int numberOfWays(string corridor) {
         int n = corridor.size();
      
        // dp[i][j] = number of ways to divide corridor from index i with j seats in current section
        // j can be 0, 1, or 2 (representing seats count in current section)
        int dp[n][3];
        memset(dp, -1, sizeof(dp));
      
        const int MOD = 1e9 + 7;
      
        // Recursive function with memoization
        // Parameters:
        // - currentIndex: current position in corridor
        // - seatsInSection: number of seats in current section (0, 1, or 2)
        auto dfs = [&](this auto&& dfs, int currentIndex, int seatsInSection) -> int {
            // Base case: reached end of corridor
            if (currentIndex >= n) {
                // Valid only if last section has exactly 2 seats
                return seatsInSection == 2 ? 1 : 0;
            }
          
            // Return memoized result if already computed
            if (dp[currentIndex][seatsInSection] != -1) {
                return dp[currentIndex][seatsInSection];
            }
          
            // Update seats count if current position has a seat
            int newSeatsCount = seatsInSection;
            if (corridor[currentIndex] == 'S') {
                newSeatsCount++;
            }
          
            // Invalid case: more than 2 seats in a section
            if (newSeatsCount > 2) {
                return dp[currentIndex][seatsInSection] = 0;
            }
          
            // Option 1: Continue with current section (don't place divider)
            dp[currentIndex][seatsInSection] = dfs(currentIndex + 1, newSeatsCount);
          
            // Option 2: If current section has 2 seats, we can place a divider
            // and start a new section
            if (newSeatsCount == 2) {
                dp[currentIndex][seatsInSection] = 
                    (dp[currentIndex][seatsInSection] + dfs(currentIndex + 1, 0)) % MOD;
            }
          
            return dp[currentIndex][seatsInSection];
        };
      
        // Start from index 0 with 0 seats in the first section
        return dfs(0, 0);
    }
};