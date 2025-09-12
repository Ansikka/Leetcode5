class Solution {
public:
    bool doesAliceWin(string s) {
             const string VOWELS = "aeiou";
      
        // Iterate through each character in the input string
        for (char c : s) {
            // Check if the current character is a vowel
            // find() returns npos if the character is not found
            if (VOWELS.find(c) != string::npos) {
                // If any vowel is found, Alice wins
                return true;
            }
        }
      
        // If no vowels are found in the string, Alice doesn't win
        return false;
    }
};