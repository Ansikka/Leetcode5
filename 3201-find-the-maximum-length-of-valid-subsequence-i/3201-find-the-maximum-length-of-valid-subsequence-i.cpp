class Solution {
public:
    int maximumLength(vector<int>& nums) {
         const int k = 2; // Modulo divisor to handle the remainders (can be adjusted based on requirements)
        int dp[k][k];    // Dynamic programming table to store longest lengths for each remainder pair
        memset(dp, 0, sizeof(dp)); // Initialize the dp table with zeroes
        int maxLength = 0; // Variable to store the maximum length found

        // Iterate through each number in the input vector
        for (int num : nums) {
            int remainder = num % k; // Find the remainder of the number with respect to k

            for (int j = 0; j < k; ++j) {
                int requiredRemainder = (j - remainder + k) % k; // Calculate the remainder needed to form the sequence

                // Update the dp table with the new length found and track the maximum
                dp[remainder][requiredRemainder] = dp[requiredRemainder][remainder] + 1;

                // Update the maximum length found so far
                maxLength = std::max(maxLength, dp[remainder][requiredRemainder]);
            }
        }
        return maxLength; 
    }
};