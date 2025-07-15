class Solution {
public:
    bool isValid(string word) {
         if (word.size() < 3) {
            return false;
        }

        // Flags to check the presence of vowels and consonants
        bool hasVowel = false;
        bool hasConsonant = false;
      
        // Boolean array to mark vowels
        bool vowelStatus[26] = {false};
        std::string vowels = "aeiou";
      
        // Mark vowels in the boolean array
        for (char c : vowels) {
            vowelStatus[c - 'a'] = true;
        }
      
        // Iterate over each character in the word
        for (char c : word) {
            if (std::isalpha(c)) { // Check if the character is a letter
                if (vowelStatus[std::tolower(c) - 'a']) {
                    hasVowel = true; // The letter is a vowel
                } else {
                    hasConsonant = true; // The letter is a consonant
                }
            } else if (!std::isdigit(c)) { // Check if the character is not a digit (invalid character)
                return false;
            }
        }
      
        // Valid if both a vowel and a consonant are present
        return hasVowel && hasConsonant;
    }
};