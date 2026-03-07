class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
      
        # Target pattern for alternating string starting with '0'
        target_pattern = "01"
      
        # Count mismatches when comparing s with pattern "010101..."
        # For each position i, check if s[i] matches the expected character
        mismatch_count = sum(char != target_pattern[i & 1] for i, char in enumerate(s))
      
        # The answer is minimum between:
        # 1. Flips needed for pattern "010101..." (mismatch_count)
        # 2. Flips needed for pattern "101010..." (n - mismatch_count)
        min_flips = min(mismatch_count, n - mismatch_count)
      
        # Simulate rotating the string by removing from front and adding to back
        # This handles the Type-1 operation (moving first char to end)
        for i in range(n):
            # Remove contribution of character at position i (as if it's moved to end)
            mismatch_count -= s[i] != target_pattern[i & 1]
          
            # Add contribution of the same character at its new position (i + n)
            mismatch_count += s[i] != target_pattern[(i + n) & 1]
          
            # Update minimum flips considering both alternating patterns
            min_flips = min(min_flips, mismatch_count, n - mismatch_count)
      
        return min_flips