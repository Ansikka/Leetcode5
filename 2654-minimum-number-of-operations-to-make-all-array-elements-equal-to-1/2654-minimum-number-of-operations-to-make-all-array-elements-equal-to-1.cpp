class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
      
        // Count how many 1s already exist in the array
        int onesCount = 0;
        for (int num : nums) {
            if (num == 1) {
                ++onesCount;
            }
        }
      
        // If there are already 1s in the array, we need (n - onesCount) operations
        // to convert all other elements to 1
        if (onesCount > 0) {
            return n - onesCount;
        }
      
        // Find the minimum length subarray whose GCD is 1
        int minLength = n + 1;
        for (int i = 0; i < n; ++i) {
            int currentGcd = 0;
            for (int j = i; j < n; ++j) {
                // Calculate GCD of subarray nums[i..j]
                currentGcd = gcd(currentGcd, nums[j]);
              
                // If GCD becomes 1, update minimum length
                if (currentGcd == 1) {
                    minLength = min(minLength, j - i + 1);
                    break;  // No need to extend this subarray further
                }
            }
        }
      
        // If no subarray has GCD of 1, it's impossible to create any 1s
        if (minLength > n) {
            return -1;
        }
      
        // Total operations: (minLength - 1) to create the first 1,
        // then (n - 1) operations to convert all other elements to 1
        return (minLength - 1) + (n - 1);
    }
};