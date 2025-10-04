class Solution {
public:
    int maxArea(vector<int>& height) {
           int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
      
        // Use two-pointer technique to find maximum water container
        while (left < right) {
           
            int currentArea = min(height[left], height[right]) * (right - left);
          
            // Update maximum water area if current is larger
            maxWater = max(maxWater, currentArea);
          
           
            if (height[left] < height[right]) {
                ++left;  // Move left pointer rightward if left line is shorter
            } else {
                --right;  // Move right pointer leftward if right line is shorter (or equal)
            }
        }
      
        return maxWater;
    }
};