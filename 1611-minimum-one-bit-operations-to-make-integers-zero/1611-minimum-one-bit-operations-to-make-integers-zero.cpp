class Solution {
public:
    int minimumOneBitOperations(int n) {
             // Initialize the result variable to store the Gray code inverse
        int result = 0;
      
        
        while (n > 0) {
            // XOR the current result with n
            result ^= n;
          
            // Right shift n by 1 bit for the next iteration
            n >>= 1;
        }
      
        return result;
    }
};