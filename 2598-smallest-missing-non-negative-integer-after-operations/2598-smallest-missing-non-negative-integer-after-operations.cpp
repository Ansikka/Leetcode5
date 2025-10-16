class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
                int remainderCount[value];
        memset(remainderCount, 0, sizeof(remainderCount));
      
     
        for (int num : nums) {
            int remainder = ((num % value) + value) % value;
            ++remainderCount[remainder];
        }
      
      
        for (int i = 0; ; ++i) {
            int remainderClass = i % value;
          
            // If no number in this remainder class is available, return i
            if (remainderCount[remainderClass] == 0) {
                return i;
            }
          
            // Use one number from this remainder class
           --remainderCount[remainderClass];
        }
    }
};