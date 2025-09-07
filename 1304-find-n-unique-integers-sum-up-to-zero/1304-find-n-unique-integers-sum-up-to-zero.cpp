class Solution {
public:
 
         vector<int> sumZero(int n) {
        // Create a result vector of size n
        vector<int> result(n);
      
        // Fill the array with pairs of positive and negative integers
        // For n/2 pairs, add both i and -i to ensure sum is zero
        int index = 0;
        for (int i = 1; i <= n / 2; ++i) {
            result[index++] = i;      // Add positive number
            result[index++] = -i;     // Add corresponding negative number
        }
      
        // If n is odd, the last element remains 0 (default initialized)
        // This ensures the total sum is still zero
      
        return result;  
    }
};