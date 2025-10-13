class Solution {
public:
     vector<string> removeAnagrams(vector<string>& words) {
        // Lambda function to check if two strings are NOT anagrams
        // Returns true if strings are different (not anagrams), false if they are anagrams
        auto areNotAnagrams = [](const string& str1, const string& str2) -> bool {
            // Different lengths mean they cannot be anagrams
            if (str1.size() != str2.size()) {
                return true;
            }
          
            // Count frequency of each character in the first string
            int charFrequency[26] = {0};
            for (const char& ch : str1) {
                charFrequency[ch - 'a']++;
            }
          
            // Decrement frequency for each character in the second string
            // If any frequency goes negative, strings are not anagrams
            for (const char& ch : str2) {
                charFrequency[ch - 'a']--;
                if (charFrequency[ch - 'a'] < 0) {
                    return true;
                }
            }
          
            // All frequencies match, strings are anagrams
            return false;
        };
      
        // Result vector starts with the first word (it's never removed)
        vector<string> result;
        result.push_back(words[0]);
      
        // Iterate through remaining words and keep only those that are not
        // anagrams of their immediate predecessor
        for (int i = 1; i < words.size(); i++) {
            if (areNotAnagrams(words[i - 1], words[i])) {
                result.push_back(words[i]);
            }
        }
      
        return result;
    }
};