class Solution {
public:
    int countHillValley(vector<int>& nums) {
           int count = 0; // Initialize counter for hills and valleys to zero

        // We use two pointers, 'previous' to keep track of the last distinct element
        // and 'current' which will iterate through the vector, starting from index 1
        for (int current = 1, previous = 0; current < nums.size() - 1; ++current) {
          
            // Skip over duplicate adjacent values
            if (nums[current] == nums[current + 1]) {
                continue;
            }
          
            // Check if nums[current] forms a hill
            if (nums[current] > nums[previous] && nums[current] > nums[current + 1]) {
                ++count; // Increment count if we found a hill
            }
          
            // Check if nums[current] forms a valley
            if (nums[current] < nums[previous] && nums[current] < nums[current + 1]) {
                ++count; // Increment count if we found a valley
            }
          
            // Update 'previous' to the last distinct element's index
            previous = current;
        }
      
        return count;
    }
};