class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        """
        Find all possible times a binary watch could display given the number of LEDs turned on.
      
        A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59).
        We need to find all valid times where the total number of lit LEDs equals turnedOn.
      
        Args:
            turnedOn: The number of LEDs currently turned on (0-10)
          
        Returns:
            List of valid times in "H:MM" format
        """
        # List to store all valid time combinations
        result = []
      
        # Iterate through all possible hours (0-11)
        for hour in range(12):
            # Iterate through all possible minutes (0-59)
            for minute in range(60):
                # Count the number of 1s in binary representation of both hour and minute
                # bin() returns string like '0b101', so we count '1' characters
                hour_bits = bin(hour).count('1')
                minute_bits = bin(minute).count('1')
              
                # Check if total lit LEDs matches the required number
                if hour_bits + minute_bits == turnedOn:
                    # Format time as "H:MM" (hour without leading zero, minute with leading zero)
                    time_string = f"{hour}:{minute:02d}"
                    result.append(time_string)
      
        return result
