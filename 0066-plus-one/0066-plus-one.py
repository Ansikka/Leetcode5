from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Adds one to the integer represented by the array of digits.
      
        Args:
            digits: List of integers where each element is a single digit (0-9)
      
        Returns:
            List of integers representing the result of adding one
        """
        n = len(digits)
      
        # Iterate through digits from right to left (least significant to most significant)
        for i in range(n - 1, -1, -1):
            # Add 1 to the current digit
            digits[i] += 1
          
            # Handle carry by taking modulo 10
            digits[i] %= 10
          
            # If the digit is not 0, there's no carry, so we can return
            if digits[i] != 0:
                return digits
      
        # If we reach here, all digits were 9 (e.g., 999 -> 1000)
        # Need to add a leading 1
        return [1] + digits