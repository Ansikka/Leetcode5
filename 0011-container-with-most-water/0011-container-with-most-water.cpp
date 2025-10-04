class Solution {
public:
    int maxArea(vector<int>& height) {
           int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
      
        // Use two-pointer technique to find maximum water container
        while (left < right) {
            // Calculate current water area: minimum height × width
            // Water level is limited by the shorter line
            int currentArea = min(height[left], height[right]) * (right - left);
          
            // Update maximum water area if current is larger
            maxWater = max(maxWater, currentArea);
          
            // Move the pointer pointing to the shorter line inward
            // This greedy approach works because:
            // - Moving the shorter line might find a taller line (potentially increasing area)
            // - Moving the taller line will definitely decrease width without guarantee of height increase
            if (height[left] < height[right]) {
                ++left;  // Move left pointer rightward if left line is shorter
            } else {
                --right;  // Move right pointer leftward if right line is shorter (or equal)
            }
        }
      
        return maxWater;
    }
};