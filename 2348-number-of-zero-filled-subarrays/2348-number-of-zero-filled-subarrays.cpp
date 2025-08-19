class Solution {
public:
 
   long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0; // Variable to store the final answer.
        int zeroCount = 0; // Counter to keep track of consecutive zeros.

        // Iterate through the numbers in the vector.
        for (int value : nums) {
            // Reset the counter if the current value is not zero, otherwise increase it.
            zeroCount = (value != 0) ? 0 : zeroCount + 1;
          
            // Add the number of new zero-filled subarrays ending with the current value.
            answer += zeroCount;
        }
      
        // Return the total number of zero-filled subarrays found.
        return answer;
    }
};