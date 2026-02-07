class Solution:
    def minimumDeletions(self, s: str) -> int:
        # Get the length of the input string
        n = len(s)
      
        # dp[i] represents minimum deletions needed to make s[0:i] balanced
        # We use n+1 size to handle 1-indexed iteration
        dp = [0] * (n + 1)
      
        # Count of 'b' characters seen so far
        b_count = 0
      
        # Iterate through each character with 1-based indexing
        for i, char in enumerate(s, 1):
            if char == 'b':
                # If current character is 'b', no additional deletion needed
                # The string remains balanced up to this point
                dp[i] = dp[i - 1]
                b_count += 1
            else:
                # If current character is 'a', we have two choices:
                # 1. Delete this 'a' (cost: dp[i-1] + 1)
                # 2. Keep this 'a' and delete all previous 'b's (cost: b_count)
                dp[i] = min(dp[i - 1] + 1, b_count)
      
        # Return the minimum deletions needed for the entire string
        return dp[n]