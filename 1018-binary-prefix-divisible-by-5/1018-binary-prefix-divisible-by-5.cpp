class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int currentRemainder = 0;
      
        // Process each binary digit in the array
        for (int binaryDigit : nums) {
            // Left shift the current value (multiply by 2) and add the new binary digit
            // Then take modulo 5 to keep the remainder manageable
            currentRemainder = ((currentRemainder << 1) | binaryDigit) % 5;
          
            // Check if the current prefix forms a number divisible by 5
            // (remainder equals 0 means divisible by 5)
            result.push_back(currentRemainder == 0);
        }
      
        return result;
    }
};