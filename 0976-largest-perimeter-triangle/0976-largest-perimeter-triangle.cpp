class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
      
        // Iterate from the largest elements to find valid triangle
        // Starting from the end ensures we get the maximum perimeter
        for (int i = nums.size() - 1; i >= 2; --i) {
            // For a valid triangle: sum of two smaller sides > largest side
            // Check if nums[i-2] + nums[i-1] > nums[i]
            int sumOfTwoSmallerSides = nums[i - 1] + nums[i - 2];
          
            if (sumOfTwoSmallerSides > nums[i]) {
                // Valid triangle found, return the perimeter
                return sumOfTwoSmallerSides + nums[i];
            }
        }
      
        // No valid triangle can be formed
        return 0;
    }
};