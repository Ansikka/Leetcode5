from typing import List
from itertools import accumulate


class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        # Initialize difference array for tracking move costs
        # Size is 2*limit+2 to handle all possible sums from 2 to 2*limit
        diff_array = [0] * (2 * limit + 2)
        n = len(nums)
      
        # Process each pair (nums[i], nums[n-1-i])
        for i in range(n // 2):
            left_val = nums[i]
            right_val = nums[n - 1 - i]
          
            # Ensure left_val <= right_val for consistent processing
            if left_val > right_val:
                left_val, right_val = right_val, left_val
          
            # Build difference array using range update technique:
            # - Start with 2 moves needed for all sums (worst case)
            diff_array[2] += 2
          
            # - From sum (left_val + 1) onwards, only 1 move needed
            diff_array[left_val + 1] -= 2
            diff_array[left_val + 1] += 1
          
            # - At exact sum (left_val + right_val), 0 moves needed
            diff_array[left_val + right_val] -= 1
          
            # - After exact sum, back to 1 move needed
            diff_array[left_val + right_val + 1] += 1
          
            # - Beyond (right_val + limit), back to 2 moves needed
            diff_array[right_val + limit + 1] -= 1
            diff_array[right_val + limit + 1] += 2
      
        # Apply prefix sum to get actual move counts for each target sum
        # Return minimum moves needed (skip indices 0 and 1 as sums start from 2)
        return min(accumulate(diff_array[2:]))