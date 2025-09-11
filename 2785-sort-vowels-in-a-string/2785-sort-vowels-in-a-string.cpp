class Solution {
public:
       string sortVowels(string s) {
        // Extract all vowels from the string
        string vowels;
        for (char c : s) {
            char lowerChar = tolower(c);
            // Check if the character is a vowel (case-insensitive check)
            if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || 
                lowerChar == 'o' || lowerChar == 'u') {
                vowels.push_back(c);
            }
        }
      
        // Sort the extracted vowels in ascending order
        ranges::sort(vowels);
      
        // Replace vowels in original string with sorted vowels
        int vowelIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            char lowerChar = tolower(s[i]);
            // If current position is a vowel, replace with sorted vowel
            if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || 
                lowerChar == 'o' || lowerChar == 'u') {
                s[i] = vowels[vowelIndex++];
            }
        }
      
        return s;
 
    }
};