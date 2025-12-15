class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
          long long totalPeriods = 0;
        int n = prices.size();
      
        // Process each descent sequence
        for (int startIdx = 0, endIdx = 0; startIdx < n; startIdx = endIdx) {
            // Initialize end pointer to next position
            endIdx = startIdx + 1;
          
            // Extend the descent sequence while consecutive elements decrease by exactly 1
            while (endIdx < n && prices[endIdx - 1] - prices[endIdx] == 1) {
                ++endIdx;
            }
          
            // Calculate the length of current descent sequence
            int sequenceLength = endIdx - startIdx;
          
            // Add all possible subarrays in this descent sequence
            // For a sequence of length k, there are k*(k+1)/2 subarrays
            totalPeriods += (1LL + sequenceLength) * sequenceLength / 2;
        }
      
        return totalPeriods;
    }
};