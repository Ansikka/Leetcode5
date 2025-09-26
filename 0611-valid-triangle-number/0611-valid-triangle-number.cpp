class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Sort the array to enable binary search and ensure a <= b <= c
        sort(nums.begin(), nums.end());
      
        int count = 0;
        int n = nums.size();
      
        // Iterate through all possible pairs of first two sides
        for (int i = 0; i < n - 2; ++i) {
            // Skip if current element is 0 (cannot form valid triangle with 0)
            if (nums[i] == 0) {
                continue;
            }
          
            for (int j = i + 1; j < n - 1; ++j) {
                // For sides a = nums[i] and b = nums[j], find the largest valid c
                // Triangle inequality: a + b > c (other conditions automatically satisfied due to sorting)
                // Find the rightmost position where nums[k] < nums[i] + nums[j]
                int targetSum = nums[i] + nums[j];
              
                // Binary search for the first element >= targetSum
                int k = lower_bound(nums.begin() + j + 1, nums.end(), targetSum) - nums.begin();
              
                // All elements from index (j+1) to (k-1) can be the third side
                // k-1 is the last valid index, so count = (k-1) - j
                count += (k - 1) - j;
            }
        }
      
        return count;
    }
};