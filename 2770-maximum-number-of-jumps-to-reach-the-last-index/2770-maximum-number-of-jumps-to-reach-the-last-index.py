class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        from functools import cache
        from math import inf
      
        @cache
        def dfs(current_index: int) -> int:
            """
            Recursive function to find maximum jumps from current_index to the last index.
          
            Args:
                current_index: The current position in the array
              
            Returns:
                Maximum number of jumps from current_index to reach the last index,
                or -inf if it's impossible
            """
            # Base case: reached the last index
            if current_index == array_length - 1:
                return 0
          
            # Initialize maximum jumps to negative infinity (impossible case)
            max_jumps = -inf
          
            # Try jumping to every subsequent index
            for next_index in range(current_index + 1, array_length):
                # Check if jump is valid (difference between values is within target)
                if abs(nums[current_index] - nums[next_index]) <= target:
                    # Recursively calculate jumps from next_index and add 1 for current jump
                    max_jumps = max(max_jumps, 1 + dfs(next_index))
          
            return max_jumps
      
        # Initialize array length
        array_length = len(nums)
      
        # Start DFS from index 0
        result = dfs(0)
      
        # Return -1 if no valid path exists, otherwise return the result
        return -1 if result < 0 else result
