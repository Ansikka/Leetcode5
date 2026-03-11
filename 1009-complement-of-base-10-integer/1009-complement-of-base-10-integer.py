class Solution:
    def bitwiseComplement(self, n: int) -> int:
        # Special case: complement of 0 is 1
        if n == 0:
            return 1
      
        # Initialize result and bit position counter
        result = 0
        bit_position = 0
      
        # Process each bit of n from right to left
        while n > 0:
            # Get the rightmost bit, flip it (XOR with 1), 
            # shift it to the correct position, and add to result
            flipped_bit = (n & 1) ^ 1
            result |= flipped_bit << bit_position
          
            # Move to the next bit position
            bit_position += 1
          
            # Right shift n to process the next bit
            n >>= 1
      
        return result