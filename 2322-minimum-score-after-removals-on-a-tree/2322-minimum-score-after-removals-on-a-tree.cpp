class Solution {
public:
    
     vector<int> values;  // Values corresponding to each node
    int totalXor;        // XOR of all values
    int subtreeXor;      // XOR of the values in a subtree
    int nodeCount;       // Number of nodes in the graph
    int minDifference = INT_MAX; // Minimum absolute difference between the XOR of three parts
    vector<vector<int>> graph; // Adjacency list representation of the graph

    // Main function that solves the problem by iterating over each edge 
    // and considering it as a potential cut to form two trees
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        nodeCount = nums.size();
        graph.resize(nodeCount, vector<int>());

        // Construct the graph
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        // Calculate the totalXor for all the values
        totalXor = 0;
        for (int& v : nums) totalXor ^= v;

        // Store the given values
        values = nums;

        // Iterate over all nodes and their connected nodes
        for (int i = 0; i < nodeCount; ++i) {
            for (int neighbor : graph[i]) {
                // Find the XOR for one subtree
                subtreeXor = dfs(i, -1, neighbor);
                // Attempt to find the minimum difference by cutting another edge in the formed subtree
                dfs2(i, -1, neighbor);
            }
        }
        return minDifference;
    }

    // DFS to find the XOR of all values under the current node, ignoring the parent and the excluded node x
    int dfs(int current, int parent, int excludedNode) {
        int currentXor = values[current];
        for (int next : graph[current])
            if (next != parent && next != excludedNode) 
                currentXor ^= dfs(next, current, excludedNode);
        return currentXor;
    }

    // Second DFS to try out different cuts in the subtree rooted at 'current' and calculate the resulting minimum difference
    int dfs2(int current, int parent, int excludedNode) {
        int currentXor = values[current];
        for (int next : graph[current])
            if (next != parent && next != excludedNode) {
                int a = dfs2(next, current, excludedNode);
                currentXor ^= a;
                int b = subtreeXor ^ a;
                int c = totalXor ^ subtreeXor;
                int maxPart = max(max(a, b), c);
                int minPart = min(min(a, b), c);
                int difference = maxPart - minPart;
                minDifference = min(minDifference, difference);
            }
        return currentXor;
    }
};