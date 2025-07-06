class Solution {
public:
    int jump(vector<int>& nums) {
         int jumps = 0;      // Number of jumps made so far
        int farthest = 0;   // The farthest index reachable at the current step
        int end = 0;        // The end of the range for the current jump

        // We do not need to consider the last position, because we never need to jump from it
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest we can reach from current position
            farthest = std::max(farthest, i + nums[i]);

        
            if (i == end) {
                ++jumps;
                end = farthest;
            }
        }
        return jumps;
    }
};