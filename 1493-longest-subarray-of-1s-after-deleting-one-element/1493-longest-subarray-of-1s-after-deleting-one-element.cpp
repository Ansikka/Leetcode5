class Solution {
public:
    int longestSubarray(vector<int>& nums) {
                int size = nums.size();

        // Create two vectors to keep track of consecutive 1's on the left and right
        vector<int> left(size, 0);
        vector<int> right(size, 0);

        // Fill the left array with the counts of consecutive 1's from the left
        for (int i = 1; i < size; ++i) {
            if (nums[i - 1] == 1) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Fill the right array with the counts of consecutive 1's from the right
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i + 1] == 1) {
                right[i] = right[i + 1] + 1;
            }
        }

        // Initialize the variable to store the maximum length of the subarray
        int max_length = 0;

        // Iterate over the input array to compute the maximum subarray length
        for (int i = 0; i < size; ++i) {
            // The longest subarray is the sum of consecutive 1's to the left and right of the current element
            max_length = max(max_length, left[i] + right[i]);
        }

        // Return the computed maximum subarray length
        return max_length;

    }
};