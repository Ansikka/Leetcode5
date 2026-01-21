class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        """
        For each number in nums, find the minimum value y such that y | (y + 1) = num.
        If no such value exists, return -1 for that position.
      
        Args:
            nums: List of integers to process
          
        Returns:
            List of minimum values or -1 if no valid value exists
        """
        result = []
      
        for num in nums:
            # Special case: when num is 2, no valid y exists
            # Because if y | (y + 1) = 2 (binary: 10), there's no valid y
            if num == 2:
                result.append(-1)
            else:
                # Find the rightmost 0 bit in num's binary representation
                # Starting from bit position 1 (2^1 = 2)
                for bit_position in range(1, 32):
                    # Check if the bit at current position is 0
                    # (x >> i) & 1 gives the bit at position i
                    # ^ 1 flips it, so we're checking if bit is 0
                    if ((num >> bit_position) & 1) ^ 1:
                        # Found the rightmost 0 bit at position bit_position
                        # Flip the bit at position (bit_position - 1) to get the answer
                        # This gives us the minimum y where y | (y + 1) = num
                        result.append(num ^ (1 << (bit_position - 1)))
                        break
      
        return result