class Solution {
public:
    int smallestRepunitDivByK(int k) {
            int remainder = 1 % k;
      
        // Try repunits of length 1 to k
        // If no solution exists within k iterations, there's no solution at all
        // This is because by pigeonhole principle, remainders will repeat within k iterations
        for (int length = 1; length <= k; ++length) {
            // Check if current repunit is divisible by k (remainder is 0)
            if (remainder == 0) {
                return length;
            }
          
            // Calculate remainder of next repunit
            // Next repunit = current * 10 + 1
            // Using modular arithmetic: (a * 10 + 1) % k = ((a % k) * 10 + 1) % k
            remainder = (remainder * 10 + 1) % k;
        }
      
        // No repunit divisible by k exists
        return -1;
    }
};