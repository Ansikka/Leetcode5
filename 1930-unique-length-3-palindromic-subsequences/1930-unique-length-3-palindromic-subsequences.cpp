class Solution {
public:
    int countPalindromicSubsequence(string s) {
           int result = 0;
      
        // Iterate through each possible character that could be at both ends of palindrome
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            // Find the first and last occurrence of current character
            int firstIndex = s.find_first_of(ch);
            int lastIndex = s.find_last_of(ch);
          
            // Skip if character doesn't exist or appears only once
            if (firstIndex == string::npos || firstIndex == lastIndex) {
                continue;
            }
          
            // Use bitmask to track unique characters between first and last occurrence
            int characterMask = 0;
          
            // Check all characters between first and last occurrence
            for (int i = firstIndex + 1; i < lastIndex; ++i) {
                // Convert character to 0-based index (a=0, b=1, ..., z=25)
                int charIndex = s[i] - 'a';
              
                // Check if this character hasn't been seen yet using bit manipulation
                // (mask >> charIndex) & 1 gets the bit at position charIndex
                // ^ 1 inverts it (0 becomes 1, 1 becomes 0)
                // So the condition is true when bit is 0 (character not seen)
                if (((characterMask >> charIndex) & 1) == 0) {
                    // Mark this character as seen by setting its bit to 1
                    characterMask |= (1 << charIndex);
                    // Each unique character forms a valid palindrome with ch at both ends
                    ++result;
                }
            }
        }
      
        return result;
    }
};