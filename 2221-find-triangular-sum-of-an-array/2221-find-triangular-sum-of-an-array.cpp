class Solution {
public:
    int triangularSum(vector<int>& nums) {
           for (int level_size = nums.size() - 1; level_size > 0; --level_size) {
            // For each level, calculate new values by summing adjacent pairs
            // Store the result in-place, overwriting the left element
            for (int i = 0; i < level_size; ++i) {
                // Add current element with next element and take modulo 10
                // This simulates the triangular sum operation
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
      
        // After all iterations, the result is stored in the first element
        return nums[0];
    }
};