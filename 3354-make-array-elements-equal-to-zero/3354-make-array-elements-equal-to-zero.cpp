class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
      
        // Initialize the result counter and left sum accumulator
        int validCount = 0;
        int leftSum = 0;
      
        // Iterate through each element in the array
        for (int currentNum : nums) {
            if (currentNum != 0) {
                // If current element is non-zero, add it to the left sum
                leftSum += currentNum;
            } else {
                // If current element is zero, check if this position is valid
              
                // Calculate the right sum (total - left)
                int rightSum = totalSum - leftSum;
              
                if (leftSum == rightSum) {
                    // If left and right sums are equal, both directions are valid
                    validCount += 2;
                } else if (abs(leftSum - rightSum) == 1) {
                    // If the difference between left and right sums is exactly 1,
                    // one direction is valid
                    validCount++;
                }
            }
        }
      
        return validCount; 
    }
};