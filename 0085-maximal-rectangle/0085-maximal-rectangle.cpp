class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix[0].size();
        vector<int> height(n + 1, 0);
        int ans =0;

        for(auto&  row : matrix){
            for(int i=0; i<n; ++i){
                height[i] = row[i] == '1' ? height[i] + 1: 0;

            }
            stack<int> s;
            for(int i =0; i <=n; ++i){
                while (!s.empty() && height[i] < height[s.top()]){
                    int h =height[s.top()];
                    s.pop();
                    int w = s.empty() ? i : i - s.top() - 1;
                    ans = max(ans, h * w);
                }
                s.push(i);
            }
        }
        return ans;
    }
};