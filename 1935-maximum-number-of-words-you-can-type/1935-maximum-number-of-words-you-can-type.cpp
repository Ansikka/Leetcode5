class Solution {
public:
     int canBeTypedWords(string text, string brokenLetters) {
        // Create a boolean array to mark which letters are broken
        // Index represents letter position (0 for 'a', 1 for 'b', etc.)
        bool isBroken[26] = {false};
      
        // Mark all broken letters in the array
        for (char letter : brokenLetters) {
            isBroken[letter - 'a'] = true;
        }
      
        // Split the text into words and count typeable words
        int typeableWordCount = 0;
        vector<string> words = split(text, ' ');
      
        // Check each word to see if it can be typed
        for (const string& word : words) {
            bool canTypeWord = true;
          
            // Check if any character in the word is broken
            for (char character : word) {
                if (isBroken[character - 'a']) {
                    canTypeWord = false;
                    break;
                }
            }
          
            // Increment count if word can be typed
            if (canTypeWord) {
                typeableWordCount++;
            }
        }
      
        return typeableWordCount;
    }

private:
    // Helper function to split a string by a delimiter character
    vector<string> split(const string& inputString, char delimiter) {
        vector<string> result;
        string currentWord;
      
        // Iterate through each character in the input string
        for (char currentChar : inputString) {
            if (currentChar == delimiter) {
                // Found delimiter, add current word to result
                result.push_back(currentWord);
                currentWord.clear();
            } else {
                // Build the current word
                currentWord.push_back(currentChar);
            }
        }
      
        // Add the last word (no delimiter after it)
        result.push_back(currentWord);
      
        return result;
    }
};