class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        Find the minimum element in a rotated sorted array that may contain duplicates.
        Uses binary search to achieve O(log n) average time complexity.
      
        Args:
            nums: A rotated sorted array that may contain duplicate elements
          
        Returns:
            The minimum element in the array
        """
        # Initialize binary search boundaries
        left = 0
        right = len(nums) - 1
      
        # Continue searching while the search space has more than one element
        while left < right:
            # Calculate middle index using bit shift (equivalent to // 2)
            mid = (left + right) >> 1
          
            # Case 1: Mid element is greater than right element
            # The minimum must be in the right half (after mid)
            if nums[mid] > nums[right]:
                left = mid + 1
            # Case 2: Mid element is less than right element  
            # The minimum is in the left half (including mid)
            elif nums[mid] < nums[right]:
                right = mid
            # Case 3: Mid element equals right element
            # Cannot determine which side contains minimum, safely shrink from right
            else:
                right -= 1
      
        # When left == right, we've found the minimum element
        return nums[left]