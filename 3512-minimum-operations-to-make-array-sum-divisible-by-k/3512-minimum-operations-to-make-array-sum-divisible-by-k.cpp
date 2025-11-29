class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Calculate the sum of all elements in the array
        // Using std::reduce with initial value 0
        int totalSum = reduce(nums.begin(), nums.end(), 0);
      
        // Return the remainder when sum is divided by k
        // This represents the minimum operations needed
        return totalSum % k;

    }
};