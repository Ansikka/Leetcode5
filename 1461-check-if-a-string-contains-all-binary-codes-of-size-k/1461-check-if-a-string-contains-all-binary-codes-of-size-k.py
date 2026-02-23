class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        """
        Check if the string contains all possible binary codes of length k.
      
        Args:
            s: A binary string containing only '0' and '1'
            k: The length of binary codes to check
          
        Returns:
            True if all 2^k possible binary codes of length k exist as substrings in s
        """
        string_length = len(s)
        total_possible_codes = 1 << k  # Calculate 2^k using bit shift
      
        # Early termination: if there aren't enough positions to generate all codes
        # We need at least 2^k different starting positions for substrings
        if string_length - k + 1 < total_possible_codes:
            return False
      
        # Generate all unique substrings of length k using set comprehension
        unique_substrings = {s[i:i + k] for i in range(string_length - k + 1)}
      
        # Check if we found all possible binary codes
        return len(unique_substrings) == total_possible_codes