class Solution {
public:
  
  

   int maxFreqSum(string s) {
        // Array to store frequency count of each letter (a-z)
        int frequency[26]{};
      
        // Count the frequency of each character in the string
        for (char c : s) {
            ++frequency[c - 'a'];
        }
      
        // Variables to track maximum frequency of vowels and consonants
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
      
        // Iterate through all 26 letters to find max frequencies
        for (int i = 0; i < 26; ++i) {
            char currentChar = 'a' + i;
          
            // Check if current character is a vowel
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || 
                currentChar == 'o' || currentChar == 'u') {
                // Update maximum vowel frequency if current is greater
                maxVowelFreq = max(maxVowelFreq, frequency[i]);
            } else {
                // Update maximum consonant frequency if current is greater
                maxConsonantFreq = max(maxConsonantFreq, frequency[i]);
            }
        }
      
        // Return sum of maximum vowel frequency and maximum consonant frequency
        return maxVowelFreq + maxConsonantFreq;
    }
};