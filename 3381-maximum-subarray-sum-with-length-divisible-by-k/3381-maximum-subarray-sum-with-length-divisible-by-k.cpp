class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
               using ll = long long;
      
        // Initialize constants
        const ll INF = 1e18;
      
        // minPrefixSum[i] stores the minimum prefix sum seen so far 
        // for indices with remainder i when divided by k
        vector<ll> minPrefixSum(k, INF);
      
        // Initialize the result with negative infinity
        ll maxSum = -INF;
      
        // Running prefix sum
        ll prefixSum = 0;
      
        // Set minPrefixSum[k-1] = 0 to handle subarrays starting from index 0
        // This allows selecting subarrays of length k, 2k, 3k, etc. from the beginning
        minPrefixSum[k - 1] = 0;
      
        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Update the prefix sum
            prefixSum += nums[i];
          
            // Calculate the maximum subarray sum ending at index i
            // with length that is a multiple of k
            // This is done by subtracting the minimum prefix sum at compatible positions
            maxSum = max(maxSum, prefixSum - minPrefixSum[i % k]);
          
            // Update the minimum prefix sum for the current remainder class
            minPrefixSum[i % k] = min(minPrefixSum[i % k], prefixSum);
        }
      
        return maxSum;
    }
};