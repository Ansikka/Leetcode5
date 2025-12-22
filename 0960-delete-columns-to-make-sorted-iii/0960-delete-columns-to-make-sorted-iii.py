class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # Get the length of each string (all strings have same length)
        string_length = len(strs[0])
      
        # dp[i] represents the maximum length of increasing subsequence ending at column i
        # Initialize all positions with 1 (each column itself forms a subsequence of length 1)
        dp = [1] * string_length
      
        # For each column position
        for current_col in range(string_length):
            # Check all previous columns
            for prev_col in range(current_col):
                # Check if we can extend the subsequence from prev_col to current_col
                # This is valid if for ALL strings, character at prev_col <= character at current_col
                if all(string[prev_col] <= string[current_col] for string in strs):
                    # Update the maximum subsequence length ending at current_col
                    dp[current_col] = max(dp[current_col], dp[prev_col] + 1)
      
        # The minimum columns to delete = total columns - maximum columns we can keep
        return string_length - max(dp)   