from typing import List


class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        """
        Find the maximum distance j - i where i <= j and nums1[i] <= nums2[j].

        Args:
            nums1: First list of integers (non-increasing order)
            nums2: Second list of integers (non-increasing order)

        Returns:
            Maximum distance between valid index pairs
        """
        max_distance = 0
        n2 = len(nums2)

        for i, value in enumerate(nums1):
            # Binary search to find the first index j where nums2[j] < value
            # This uses the standard template: find first true index
            left, right = i, n2 - 1
            first_true_index = -1

            while left <= right:
                mid = (left + right) // 2
                if nums2[mid] < value:  # feasible condition: pair becomes invalid
                    first_true_index = mid
                    right = mid - 1
                else:
                    left = mid + 1

            # Calculate the last valid j
            if first_true_index == -1:
                # All positions from i to end are valid
                last_valid_j = n2 - 1
            else:
                # Last valid position is one before first invalid
                last_valid_j = first_true_index - 1

            # Update maximum distance if valid pair exists
            if last_valid_j >= i:
                max_distance = max(max_distance, last_valid_j - i)

        return max_distance