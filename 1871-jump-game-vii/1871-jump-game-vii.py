class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
      
        # prefix_sum[i] stores the count of reachable positions from 0 to i-1
        prefix_sum = [0] * (n + 1)
        prefix_sum[1] = 1  # Position 0 is reachable (starting position)
      
        # reachable[i] indicates whether position i is reachable from position 0
        reachable = [True] + [False] * (n - 1)  # Only position 0 is initially reachable
      
        # Process each position from left to right
        for i in range(1, n):
            # Can only land on positions with '0'
            if s[i] == "0":
                # Calculate the range of positions we can jump from to reach position i
                # We can reach i from positions [i - maxJump, i - minJump]
                left_bound = max(0, i - maxJump)
                right_bound = i - minJump
              
                # Check if there's at least one reachable position in the valid range
                # Using prefix sum to check if any position in [left_bound, right_bound] is reachable
                if left_bound <= right_bound:
                    count_reachable = prefix_sum[right_bound + 1] - prefix_sum[left_bound]
                    reachable[i] = count_reachable > 0
          
            # Update prefix sum for the next iteration
            prefix_sum[i + 1] = prefix_sum[i] + (1 if reachable[i] else 0)
      
        # Return whether the last position is reachable
        return reachable[-1]