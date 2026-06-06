class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        """
        Calculate the absolute difference between left sum and right sum for each element.
        For each index i, left sum is the sum of elements before i, 
        and right sum is the sum of elements after i.
        """
        # Initialize left sum as 0 (no elements to the left initially)
        left_sum = 0
        # Initialize right sum as the total sum of all elements
        right_sum = sum(nums)
      
        # List to store the absolute differences
        result = []
      
        # Iterate through each element in the array
        for num in nums:
            # Exclude current element from right sum (elements after current)
            right_sum -= num
          
            # Calculate and store the absolute difference between left and right sums
            result.append(abs(left_sum - right_sum))
          
            # Include current element in left sum for next iteration
            left_sum += num
      
        return result
