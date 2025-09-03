class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });

        int n = points.size(); // The total number of points
        int ans = 0; // Initialize the count of pairs

        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1]; // Get the y-value of the current point
            int maxY = INT_MIN; // Initialize maxY with the smallest possible integer

            // Iterate through all points that come after the current point
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1]; // Get the y-value of the next point
                // If maxY is less than y2, and y2 is less than or equal to y1,
                // it means we found a pair where the second point can potentially
                // form a pair with the first, based on the y-values.
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2; // Update maxY to the new found y-value
                    ++ans; // Increment the count of pairs
                }
            }
        }
      
        return ans;
    }
};