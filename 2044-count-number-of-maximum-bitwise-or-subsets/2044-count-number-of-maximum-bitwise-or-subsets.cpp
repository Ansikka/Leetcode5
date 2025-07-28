class Solution {
public:
  int maxOrValue;         // To store the maximum OR value calculated from all numbers
    int subsetCount;        // To store the count of subsets whose OR equals maxOrValue
    vector<int> numbers;    // To store the input numbers

    // Function to calculate the count of subsets whose bitwise OR equals the maximum OR of all numbers
    int countMaxOrSubsets(vector<int>& nums) {
        numbers = nums;     // Initialize class member with input
        maxOrValue = 0;     // Initialize max OR value to 0
        subsetCount = 0;    // Initialize count of subsets to 0

        // Calculate the maximum OR value from all the numbers
        for (int x : nums) {
            maxOrValue |= x;
        }

        // Start DFS traversal to explore all subsets and count those with max OR value
        dfs(0, 0);
      
        return subsetCount;
    }

    // Recursive function to perform DFS. It takes the current index and the accumulated OR value so far.
    void dfs(int index, int currentOrValue) {
        // Base case: if we have considered all elements
        if (index == numbers.size()) {
            // If the OR value equals the max OR value, increment the counter
            if (currentOrValue == maxOrValue) {
                subsetCount++;
            }
            return;
        }

        // Case 1: Exclude the current number from the subset and continue to the next element
        dfs(index + 1, currentOrValue);

        // Case 2: Include the current number in the subset (OR the current value with this number) and continue
        dfs(index + 1, currentOrValue | numbers[index]);
    }
};