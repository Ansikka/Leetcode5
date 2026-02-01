from typing import List
from math import inf

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        # First element is fixed as the first part of our sum
        first_element = nums[0]
      
        # Initialize two variables to track the two smallest elements from index 1 onwards
        # smallest: the minimum element found so far
        # second_smallest: the second minimum element found so far
        smallest = inf
        second_smallest = inf
      
        # Iterate through all elements starting from index 1
        for current_num in nums[1:]:
            if current_num < smallest:
                # If current number is smaller than the smallest,
                # update both: previous smallest becomes second smallest
                second_smallest = smallest
                smallest = current_num
            elif current_num < second_smallest:
                # If current number is between smallest and second smallest,
                # only update second smallest
                second_smallest = current_num
      
        # Return sum of first element and two smallest elements from the rest
        return first_element + smallest + second_smallest