class Solution {
public:
 
     bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int maxValidLength = 0;      // Maximum length of valid adjacent subarrays found
        int previousLength = 0;       // Length of the previous strictly increasing segment
        int currentLength = 0;        // Length of the current strictly increasing segment
        int n = nums.size();
      
        for (int i = 0; i < n; ++i) {
            // Increment the current segment length
            ++currentLength;
          
           
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
           
                maxValidLength = max({maxValidLength, 
                                     currentLength / 2, 
                                     min(previousLength, currentLength)});
              
                // Move to the next segment
                previousLength = currentLength;
                currentLength = 0;
            }
        }
      
        return maxValidLength >= k;
    }
};