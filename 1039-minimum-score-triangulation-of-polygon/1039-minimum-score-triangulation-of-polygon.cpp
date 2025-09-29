class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
      
        // dp[i][j] stores the minimum score for triangulating the polygon 
        // formed by vertices from index i to j
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
      
        // Recursive function with memoization to find minimum triangulation score
        // Parameters: i - starting vertex index, j - ending vertex index
        // Returns: minimum score for triangulating polygon from vertex i to j
        function<int(int, int)> calculateMinScore = [&](int i, int j) -> int {
            // Base case: if only two vertices, no triangle can be formed
            if (i + 1 == j) {
                return 0;
            }
          
            // Return memoized result if already calculated
            if (dp[i][j] != 0) {
                return dp[i][j];
            }
          
            // Initialize result with a large value
            int minScore = INT_MAX;
          
            // Try all possible vertices k between i and j to form a triangle (i, k, j)
            // The polygon is then divided into three parts:
            // 1. Polygon from i to k
            // 2. Triangle (i, k, j)
            // 3. Polygon from k to j
            for (int k = i + 1; k < j; ++k) {
                int currentScore = calculateMinScore(i, k) + 
                                  calculateMinScore(k, j) + 
                                  values[i] * values[k] * values[j];
                minScore = min(minScore, currentScore);
            }
          
            // Store and return the minimum score
            dp[i][j] = minScore;
            return minScore;
        };
      
        // Calculate minimum score for the entire polygon (from vertex 0 to n-1)
        return calculateMinScore(0, n - 1);
    }
};