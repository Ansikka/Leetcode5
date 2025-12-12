class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
         ranges::sort(events, [](const vector<string>& a, const vector<string>& b) {
            int timestampA = stoi(a[1]);
            int timestampB = stoi(b[1]);
          
            // If timestamps are equal, prioritize based on event type
            // Offline events ('O') come before Message events ('M')
            if (timestampA == timestampB) {
                return a[0][2] < b[0][2];  // 'O' < 'M' in ASCII
            }
            return timestampA < timestampB;
        });

        // Initialize result array to track mention counts for each user
        vector<int> mentionCounts(numberOfUsers, 0);
      
        // Track when each user will be back online (0 means currently online)
        vector<int> offlineUntilTime(numberOfUsers, 0);
      
        // Counter for "ALL" mentions that need to be distributed later
        int pendingAllMentions = 0;

        // Process each event in chronological order
        for (const auto& event : events) {
            string eventType = event[0];
            int currentTime = stoi(event[1]);
            string eventData = event[2];

            if (eventType[0] == 'O') {  // OFFLINE event
                // User goes offline for 60 time units
                int userId = stoi(eventData);
                offlineUntilTime[userId] = currentTime + 60;
            } 
            else if (eventData[0] == 'A') {  // MESSAGE event with "ALL"
                // Increment pending mentions for all users
                pendingAllMentions++;
            } 
            else if (eventData[0] == 'H') {  // MESSAGE event with "HERE"
                // Mention only users who are currently online
                for (int userId = 0; userId < numberOfUsers; ++userId) {
                    if (offlineUntilTime[userId] <= currentTime) {
                        ++mentionCounts[userId];
                    }
                }
            } 
            else {  // MESSAGE event with specific user IDs
                // Parse space-separated user IDs (format: "id0 id1 id2...")
                stringstream stringStream(eventData);
                string userIdToken;
              
                while (stringStream >> userIdToken) {
                    // Extract numeric ID from "idX" format (skip first 2 characters)
                    int userId = stoi(userIdToken.substr(2));
                    mentionCounts[userId]++;
                }
            }
        }

        // Apply all pending "ALL" mentions to every user
        if (pendingAllMentions > 0) {
            for (int userId = 0; userId < numberOfUsers; ++userId) {
                mentionCounts[userId] += pendingAllMentions;
            }
        }

        return mentionCounts;
    }
};