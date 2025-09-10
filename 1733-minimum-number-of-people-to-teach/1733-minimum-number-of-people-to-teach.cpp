class Solution {
public:
  

   int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Set to store users who cannot communicate with at least one friend
        unordered_set<int> usersNeedingHelp;
      
        // Check each friendship pair
        for (auto& friendship : friendships) {
            int user1 = friendship[0];
            int user2 = friendship[1];
          
            // If these two users don't share a common language, add both to the set
            if (!haveCommonLanguage(user1, user2, languages)) {
                usersNeedingHelp.insert(user1);
                usersNeedingHelp.insert(user2);
            }
        }
      
        // If all friends can already communicate, no teaching needed
        if (usersNeedingHelp.empty()) {
            return 0;
        }
      
        // Count how many users needing help already know each language
        vector<int> languageCount(n + 1, 0);  // languageCount[i] = number of users who know language i
      
        for (int userId : usersNeedingHelp) {
            // For each user needing help, count the languages they already know
            for (int& languageId : languages[userId - 1]) {  // userId - 1 because users are 1-indexed
                ++languageCount[languageId];
            }
        }
      
        // Find the language known by the most users who need help
        int maxUsersKnowingLanguage = *max_element(languageCount.begin(), languageCount.end());
      
        // Minimum teachings = total users needing help - users who already know the most popular language
        return usersNeedingHelp.size() - maxUsersKnowingLanguage;
    }

private:
    // Helper function to check if two users share at least one common language
    bool haveCommonLanguage(int user1, int user2, vector<vector<int>>& languages) {
        // Check if any language of user1 matches any language of user2
        for (int language1 : languages[user1 - 1]) {  // user1 - 1 because users are 1-indexed
            for (int language2 : languages[user2 - 1]) {  // user2 - 1 because users are 1-indexed
                if (language1 == language2) {
                    return true;  // Found a common language
                }
            }
        }
        return false;
    }
};