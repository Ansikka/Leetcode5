class Solution {
public:
   
           int maxFrequencyElements(vector<int>& nums) {
        // Array to store frequency count of each element (1 <= nums[i] <= 100)
        int frequency[101] = {0};
      
        // Count the frequency of each element in nums
        for (int num : nums) {
            ++frequency[num];
        }
      
        // Variables to track the result and maximum frequency
        int totalCount = 0;
        int maxFrequency = -1;
      
        // Iterate through all frequencies to find elements with maximum frequency
        for (int freq : frequency) {
            if (maxFrequency < freq) {
                // Found a new maximum frequency
                maxFrequency = freq;
                totalCount = freq;  // Reset total count to this frequency
            } else if (maxFrequency == freq) {
                // Found another element with the same maximum frequency
                totalCount += freq;  // Add its frequency to the total
            }
        }
      
        return totalCount;
    }
};