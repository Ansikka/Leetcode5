class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        # Calculate hour hand position in degrees
        # Hour hand moves 30 degrees per hour (360/12 = 30)
        # Hour hand also moves 0.5 degrees per minute (30/60 = 0.5)
        hour_angle = 30 * hour + 0.5 * minutes
      
        # Calculate minute hand position in degrees
        # Minute hand moves 6 degrees per minute (360/60 = 6)
        minute_angle = 6 * minutes
      
        # Calculate the absolute difference between the two hands
        angle_difference = abs(hour_angle - minute_angle)
      
        # Return the smaller angle between the two possible angles
        # (the direct angle or the reflex angle)
        return min(angle_difference, 360 - angle_difference)
