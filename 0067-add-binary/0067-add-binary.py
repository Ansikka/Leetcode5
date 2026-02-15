class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        Add two binary strings and return their sum as a binary string.
      
        Args:
            a: First binary number as string (e.g., "1010")
            b: Second binary number as string (e.g., "101")
          
        Returns:
            Sum of the two binary numbers as a binary string
        """
        # Convert binary string 'a' to integer (base 2)
        decimal_a = int(a, 2)
      
        # Convert binary string 'b' to integer (base 2)
        decimal_b = int(b, 2)
      
        # Add the two decimal numbers
        decimal_sum = decimal_a + decimal_b
      
        # Convert the sum back to binary string
        # bin() returns format like '0b101', so we slice from index 2
        binary_result = bin(decimal_sum)[2:]
      
        return binary_result