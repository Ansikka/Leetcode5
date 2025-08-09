class Solution {
public:
    // Function to check if a number is a power of two
    bool isPowerOfTwo(int number) {
        // A power of two has only one bit set in binary representation.
        // Subtracting one from such a number flips all the bits after
        // the set bit (including the set bit). Performing an AND operation
        // between the number and number - 1 would then result in zero.
        // Additionally, the number must be positive to be a power of two.
        return number > 0 && (number & (number - 1)) == 0;
    }
};