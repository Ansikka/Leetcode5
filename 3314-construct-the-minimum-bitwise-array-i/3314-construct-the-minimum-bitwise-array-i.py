class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        """
        For each number in nums, find the minimum value ans[i] such that
        ans[i] OR (ans[i] + 1) = nums[i], or -1 if no such value exists.
      
        Args:
            nums: List of integers to process
          
        Returns:
            List of minimum values or -1 for each number in nums
        """
        result = []
      
        for num in nums:
            # Special case: 2 has no valid answer
            # Because 2 in binary is 10, and no value OR (value+1) can produce this
            if num == 2:
                result.append(-1)
            else:
                # Find the rightmost 0 bit in num (searching from bit position 1)
                for bit_position in range(1, 32):
                    # Check if the bit at current position is 0
                    if ((num >> bit_position) & 1) == 0:
                        # Found the rightmost 0 bit
                        # XOR with 1 shifted to the previous bit position
                        # This effectively clears the bit before the found 0
                        answer = num ^ (1 << (bit_position - 1))
                        result.append(answer)
                        break
      
        return result
        