class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
         long long powerOfTwo = 1; // Initialize powerOfTwo as 2^0
        int index = 0; // Initialize index for operations vector

        // Find the smallest power of 2 greater than or equal to k
        while (powerOfTwo < k) {
            powerOfTwo *= 2;
            ++index;
        }

        int cumulativeShift = 0; // Initialize cumulativeShift to track operations

        // Work backwards to determine the character position modifications
        while (powerOfTwo > 1) {
            if (k > powerOfTwo / 2) {
                k -= powerOfTwo / 2; // Adjust k for the second half of current range
                cumulativeShift += operations[index - 1]; // Apply corresponding operation
            }
            powerOfTwo /= 2; // Move to the next smaller range
            --index; // Adjust index to track operations correctly
        }

        // Calculate the character and return it
        return 'a' + (cumulativeShift % 26);
    }
};