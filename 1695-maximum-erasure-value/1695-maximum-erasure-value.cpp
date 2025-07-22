class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         int frequency[10001]{};
      
        // Store the size of the nums vector
        int numsSize = nums.size();
      
        // Create an array to store the prefix sum of nums
        int prefixSum[numsSize + 1];
        prefixSum[0] = 0; // Initialize the first element as 0 for correct prefix sum calculation
      
        // Populate the prefixSum array
        for (int i = 0; i < numsSize; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
      
        // Initialize the maximum sum of unique elements
        int maxSum = 0;
      
        // Initialize the start index of the current subarray
        int startIndex = 0;
      
        // Iterate through the nums array to find the max sum of a unique-subarray
        for (int i = 1; i <= numsSize; ++i) {
            int currentValue = nums[i - 1];
            // Update the startIndex to be the maximum of the current startIndex or the
            // last index where currentValue was found (to ensure uniqueness in subarray)
            startIndex = max(startIndex, frequency[currentValue]);
            // Calculate the maxSum by considering the current unique subarray sum
            maxSum = max(maxSum, prefixSum[i] - prefixSum[startIndex]);
            // Update the index in frequency array to the current position for currentValue
            frequency[currentValue] = i;
        }
      
        // Return the maximum sum of a unique element subarray
        return maxSum;
    }
};