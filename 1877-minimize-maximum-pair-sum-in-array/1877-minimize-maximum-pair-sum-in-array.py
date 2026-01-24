class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        # Sort the array in ascending order
        nums.sort()
      
        # Get the length of the array
        n = len(nums)
      
        # Calculate the maximum pair sum
        # We pair the smallest elements with the largest elements
        # to minimize the maximum pair sum
        max_pair_sum = 0
      
        # Iterate through the first half of the sorted array
        for i in range(n // 2):
            # Pair element at index i with element at index (n - 1 - i)
            # This pairs smallest with largest, second smallest with second largest, etc.
            current_pair_sum = nums[i] + nums[n - 1 - i]
          
            # Update the maximum pair sum if current pair sum is larger
            max_pair_sum = max(max_pair_sum, current_pair_sum)
      
        return max_pair_sum