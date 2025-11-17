class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
          int prevOneIndex = -(k + 1);
      
        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); ++i) {
            // Check if current element is 1
            if (nums[i] == 1) {
                // Calculate the distance between current '1' and previous '1'
                // The actual distance is (i - prevOneIndex - 1) which represents
                // the number of elements between the two 1's (excluding the 1's themselves)
                if (i - prevOneIndex - 1 < k) {
                    // If distance is less than k, the condition is violated
                    return false;
                }
                // Update the index of the most recent '1'
                prevOneIndex = i;
            }
        }
      
        // All pairs of 1's satisfy the distance requirement
        return true;
    }
};