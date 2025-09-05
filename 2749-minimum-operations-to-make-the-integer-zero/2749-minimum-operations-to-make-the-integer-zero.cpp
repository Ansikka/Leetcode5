class Solution {
public:


      int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
      
        // Try different values of k (number of operations)
        for (ll k = 1; ; ++k) {
            // Calculate the target value after k operations
            // Each operation: num1 = num1 - (2^i + num2)
            // After k operations: num1 - k * num2 - sum(2^i) = 0
            // So we need: sum(2^i) = num1 - k * num2 = x
            ll x = num1 - k * num2;
          
            // If x becomes negative, no valid solution exists for k or larger values
            if (x < 0) {
                break;
            }
          
            // Check if x can be represented as sum of exactly k powers of 2
            // Minimum bits needed: __builtin_popcountll(x) (each bit represents a power of 2)
            // Maximum bits possible: x (using all 2^0 = 1)
            // Valid if: minimum_bits <= k <= maximum_bits
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
        }
      
        // No valid k found
        return -1;   
    }
};