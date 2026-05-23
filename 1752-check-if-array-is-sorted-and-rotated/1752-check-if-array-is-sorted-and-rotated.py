class Solution:
    def check(self, nums: List[int]) -> bool:
        """
        Check if the array is a rotated sorted array.
        A rotated sorted array has at most one position where the previous element
        is greater than the current element (the rotation point).
      
        Args:
            nums: List of integers to check
          
        Returns:
            True if nums is a rotated sorted array, False otherwise
        """
        # Count the number of positions where previous element > current element
        # For index i, nums[i-1] refers to the previous element
        # When i=0, nums[-1] is the last element (circular comparison)
        break_count = 0
      
        for i, current_value in enumerate(nums):
            # Check if previous element is greater than current element
            # This creates a circular comparison (last element compares with first)
            if nums[i - 1] > current_value:
                break_count += 1
      
        # A valid rotated sorted array has at most 1 break point
        return break_count <= 1