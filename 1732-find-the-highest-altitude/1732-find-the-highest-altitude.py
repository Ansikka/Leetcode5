class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        """
        Find the highest altitude reached during a trip.
      
        Args:
            gain: List of altitude gains between consecutive points
      
        Returns:
            The maximum altitude reached during the trip
        """
        from itertools import accumulate
      
        # Calculate cumulative sum of gains starting from altitude 0
        # accumulate() generates running totals: initial altitude (0) + cumulative gains
        # Example: gain = [−5, 1, 5, 0, −7] → altitudes = [0, −5, −4, 1, 1, −6]
        altitudes = accumulate(gain, initial=0)
      
        # Return the maximum altitude from all points in the journey
        return max(altitudes)