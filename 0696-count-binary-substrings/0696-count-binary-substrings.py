class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        """
        Count binary substrings with equal number of consecutive 0s and 1s.
      
        Args:
            s: Binary string containing only '0' and '1'
          
        Returns:
            Number of valid binary substrings
        """
        index = 0
        length = len(s)
        # Store counts of consecutive same characters
        group_counts = []
      
        # Group consecutive same characters and count them
        while index < length:
            current_count = 1
          
            # Count consecutive same characters
            while index + 1 < length and s[index + 1] == s[index]:
                current_count += 1
                index += 1
          
            # Add the count to our list
            group_counts.append(current_count)
            index += 1
      
        # Calculate result by taking minimum of adjacent groups
        result = 0
        for i in range(1, len(group_counts)):
            # For adjacent groups of 0s and 1s, we can form min(count1, count2) valid substrings
            result += min(group_counts[i - 1], group_counts[i])
      
        return result