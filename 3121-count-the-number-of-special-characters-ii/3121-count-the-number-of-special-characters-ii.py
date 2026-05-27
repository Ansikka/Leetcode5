from string import ascii_lowercase, ascii_uppercase

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        # Dictionary to store the first occurrence index of each character
        first_occurrence = {}
        # Dictionary to store the last occurrence index of each character
        last_occurrence = {}
      
        # Iterate through the word to record first and last occurrences
        for index, char in enumerate(word):
            # Record first occurrence if not already recorded
            if char not in first_occurrence:
                first_occurrence[char] = index
            # Always update last occurrence
            last_occurrence[char] = index
      
        # Count special characters where lowercase appears before uppercase
        # A character is special if:
        # 1. Its lowercase version exists (has a last occurrence)
        # 2. Its uppercase version exists (has a first occurrence)
        # 3. All lowercase occurrences come before all uppercase occurrences
        special_char_count = sum(
            lowercase_char in last_occurrence 
            and uppercase_char in first_occurrence 
            and last_occurrence[lowercase_char] < first_occurrence[uppercase_char]
            for lowercase_char, uppercase_char in zip(ascii_lowercase, ascii_uppercase)
        )
      
        return special_char_count