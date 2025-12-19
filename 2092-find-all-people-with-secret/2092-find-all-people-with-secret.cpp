class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
          vector<bool> knowsSecret(n);
        knowsSecret[0] = true;           // Person 0 initially knows
        knowsSecret[firstPerson] = true; // firstPerson initially knows
      
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
      
        int totalMeetings = meetings.size();
        int currentIndex = 0;
      
        // Process meetings grouped by same time
        while (currentIndex < totalMeetings) {
            // Find the range of meetings happening at the same time
            int endIndex = currentIndex;
            while (endIndex + 1 < totalMeetings && 
                   meetings[endIndex + 1][2] == meetings[currentIndex][2]) {
                endIndex++;
            }
          
            // Build adjacency list for people meeting at this time
            unordered_map<int, vector<int>> adjacencyList;
            unordered_set<int> peopleInCurrentTime;
          
            // Add all meetings at current time to the graph
            for (int k = currentIndex; k <= endIndex; k++) {
                int person1 = meetings[k][0];
                int person2 = meetings[k][1];
              
                adjacencyList[person1].push_back(person2);
                adjacencyList[person2].push_back(person1);
                peopleInCurrentTime.insert(person1);
                peopleInCurrentTime.insert(person2);
            }
          
            // BFS to spread the secret among connected people at this time
            queue<int> bfsQueue;
          
            // Start BFS from people who already know the secret
            for (int person : peopleInCurrentTime) {
                if (knowsSecret[person]) {
                    bfsQueue.push(person);
                }
            }
          
            // Spread the secret through connected components
            while (!bfsQueue.empty()) {
                int currentPerson = bfsQueue.front();
                bfsQueue.pop();
              
                // Share secret with all people meeting currentPerson
                for (int neighbor : adjacencyList[currentPerson]) {
                    if (!knowsSecret[neighbor]) {
                        knowsSecret[neighbor] = true;
                        bfsQueue.push(neighbor);
                    }
                }
            }
          
            // Move to next time group
            currentIndex = endIndex + 1;
        }
      
        // Collect all people who know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i]) {
                result.push_back(i);
            }
        }
      
        return result;
    }
};