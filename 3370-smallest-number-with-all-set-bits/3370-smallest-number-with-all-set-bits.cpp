class Solution {
public:


 int smallestNumber(int n) {
      
        int powerOfTwo = 1;
      
        while (powerOfTwo - 1 < n) {
            powerOfTwo <<= 1;  // powerOfTwo = powerOfTwo * 2
        }
      
        // Return the number with all bits set (2^k - 1)
        return powerOfTwo - 1;
    }
};