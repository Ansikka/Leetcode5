class Solution {
public:
   

   vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // Set for exact word matching (case-sensitive)
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
      
        // Map for case-insensitive matching (stores first occurrence)
        unordered_map<string, string> caseInsensitiveMap;
      
        // Map for vowel error matching (stores first occurrence)
        unordered_map<string, string> vowelPatternMap;
      
        // Lambda function to replace vowels with '*' for pattern matching
        auto replaceVowels = [](const string& word) {
            string pattern;
            for (char c : word) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    pattern += '*';
                } else {
                    pattern += c;
                }
            }
            return pattern;
        };
      
        // Build the case-insensitive and vowel pattern maps from wordlist
        for (const auto& word : wordlist) {
            // Create lowercase version for case-insensitive matching
            string lowercaseWord = word;
            transform(lowercaseWord.begin(), lowercaseWord.end(), 
                     lowercaseWord.begin(), ::tolower);
          
            // Store first occurrence for case-insensitive match
            if (!caseInsensitiveMap.count(lowercaseWord)) {
                caseInsensitiveMap[lowercaseWord] = word;
            }
          
            // Create vowel pattern and store first occurrence
            string vowelPattern = replaceVowels(lowercaseWord);
            if (!vowelPatternMap.count(vowelPattern)) {
                vowelPatternMap[vowelPattern] = word;
            }
        }
      
        // Process queries and build result
        vector<string> result;
        for (auto& query : queries) {
            // Priority 1: Check for exact match
            if (exactWords.count(query)) {
                result.emplace_back(query);
                continue;
            }
          
            // Convert query to lowercase for further matching
            string lowercaseQuery = query;
            transform(lowercaseQuery.begin(), lowercaseQuery.end(), 
                     lowercaseQuery.begin(), ::tolower);
          
            // Priority 2: Check for case-insensitive match
            if (caseInsensitiveMap.count(lowercaseQuery)) {
                result.emplace_back(caseInsensitiveMap[lowercaseQuery]);
                continue;
            }
          
            // Priority 3: Check for vowel error match
            string queryPattern = replaceVowels(lowercaseQuery);
            if (vowelPatternMap.count(queryPattern)) {
                result.emplace_back(vowelPatternMap[queryPattern]);
                continue;
            }
          
            // No match found
            result.emplace_back("");
        }
      
        return result;
    }
};