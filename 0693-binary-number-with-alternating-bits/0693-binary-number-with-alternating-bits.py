class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        """
        Check if a positive integer has alternating bits.
      
        Args:
            n: A positive integer to check
          
        Returns:
            True if the binary representation has alternating bits, False otherwise
        """
        # Initialize previous bit to -1 (invalid value) for first comparison
        previous_bit = -1
      
        # Process each bit of the number from right to left
        while n > 0:
            # Extract the rightmost bit using bitwise AND with 1
            current_bit = n & 1
          
            # Check if current bit is same as previous bit
            # If same, bits are not alternating
            if previous_bit == current_bit:
                return False
          
            # Update previous bit for next iteration
            previous_bit = current_bit
          
            # Right shift to process the next bit
            n >>= 1
      
        # All bits processed without finding consecutive same bits
        return True