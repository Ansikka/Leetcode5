class Solution {
public:
    bool canJump(vector<int>& nums) {
          
        int maxReachable = 0;
        for (int i = 0; i < nums.size(); ++i) {
   
            if (maxReachable < i) {
                return false;
            }

       
            maxReachable = max(maxReachable, i + nums[i]);
        }
    
        return true;
    }
};