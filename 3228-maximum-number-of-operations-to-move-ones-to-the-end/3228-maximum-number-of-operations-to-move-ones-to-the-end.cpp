class Solution {
public:
    int maxOperations(string s) {
         int totalOperations = 0;  // Total number of operations performed
        int onesCount = 0;         // Count of '1's encountered so far
        int stringLength = s.size();
      
        for (int i = 0; i < stringLength; ++i) {
            if (s[i] == '1') {
                // Increment count when we encounter a '1'
                ++onesCount;
            } else if (i > 0 && s[i - 1] == '1') {
                // When we encounter a '0' that follows a '1' (transition from '1' to '0'),
                // we can perform operations equal to the number of '1's seen so far
                totalOperations += onesCount;
            }
        }
      
        return totalOperations;
    }
};