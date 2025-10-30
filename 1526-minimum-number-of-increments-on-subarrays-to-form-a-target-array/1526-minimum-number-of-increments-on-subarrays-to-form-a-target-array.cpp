class Solution {
public:
    int minNumberOperations(vector<int>& target) {
      
      
        int totalOperations = target[0];
      
        // Iterate through the array starting from the second element
        for (int i = 1; i < target.size(); ++i) {
            // If current element is greater than previous element,
            // we need additional operations equal to the difference
            if (target[i] > target[i - 1]) {
                totalOperations += target[i] - target[i - 1];
            }
            // If current element is less than or equal to previous,
            // no additional operations needed (covered by previous operations)
        }
      
        return totalOperations;
    }
};