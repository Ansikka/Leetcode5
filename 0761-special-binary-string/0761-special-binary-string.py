class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        """
        Rearranges a special binary string to get the lexicographically largest result.
        A special string starts with '1', ends with '0', and has equal number of '1's and '0's
        with every prefix having at least as many '1's as '0's.
        """
        # Base case: empty string returns empty
        if not s:
            return ''
      
        # List to store special substrings found at the current level
        substrings = []
      
        # Counter to track balance of '1's and '0's
        balance = 0
      
        # Start index of current special substring
        start = 0
      
        # Iterate through the string to find special substrings
        for i in range(len(s)):
            # Increment balance for '1', decrement for '0'
            balance += 1 if s[i] == '1' else -1
          
            # When balance returns to 0, we've found a complete special substring
            if balance == 0:
                # Recursively process the inner content (excluding first '1' and last '0')
                # Then wrap it with '1' at start and '0' at end
                inner_content = self.makeLargestSpecial(s[start + 1:i])
                special_substring = '1' + inner_content + '0'
                substrings.append(special_substring)
              
                # Move start pointer to begin searching for next special substring
                start = i + 1
      
        # Sort all special substrings in descending order (lexicographically largest first)
        substrings.sort(reverse=True)
      
        # Concatenate all sorted substrings to form the final result
        return ''.join(substrings)
