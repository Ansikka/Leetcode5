class Solution {
public:

   int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Map to store the frequency count of each number in nums
        unordered_map<int, int> frequencyMap;
      
        // Map to track range boundaries using difference array technique
        // This helps count how many numbers fall within range [x-k, x+k] for each x
        map<int, int> rangeDifference;
      
        // Process each number in the input array
        for (int num : nums) {
            // Count frequency of current number
            frequencyMap[num]++;
          
            // Initialize the number as a potential target (even if count is 0)
            rangeDifference[num];
          
            // Mark range [num-k, num+k] using difference array
            // Increment at start of range
            rangeDifference[num - k]++;
            // Decrement after end of range
            rangeDifference[num + k + 1]--;
        }
      
        int maxResult = 0;
        int currentRangeCount = 0;  // Running sum for difference array
      
        // Process each position in sorted order (map keeps keys sorted)
        for (const auto& [position, difference] : rangeDifference) {
            // Update running sum to get actual count at this position
            currentRangeCount += difference;
          
            // Calculate maximum frequency achievable at this position:
            // - currentRangeCount: total numbers within k distance from position
            // - frequencyMap[position] + numOperations: existing count plus operations
            // Take minimum since we can't use more operations than available numbers in range
            maxResult = max(maxResult, min(currentRangeCount, frequencyMap[position] + numOperations));
        }
      
        return maxResult;
    }
};