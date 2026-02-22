class Solution:
    def binaryGap(self, n: int) -> int:
        """
        Find the longest distance between two consecutive 1's in the binary representation of n.
      
        Args:
            n: A positive integer
          
        Returns:
            The maximum distance between two consecutive 1's in binary representation
        """
        # Initialize the maximum distance
        max_distance = 0
      
        # Track the position of the previous 1 bit (initialize to infinity)
        previous_one_position = float('inf')
      
        # Track the current bit position (0-indexed from right)
        current_position = 0
      
        # Process each bit of n from right to left
        while n > 0:
            # Check if the current bit is 1
            if n & 1:
                # Calculate distance from previous 1 and update maximum
                max_distance = max(max_distance, current_position - previous_one_position)
                # Update the position of the most recent 1
                previous_one_position = current_position
          
            # Move to the next bit position
            current_position += 1
            # Right shift n by 1 to process the next bit
            n >>= 1
      
        return max_distance
