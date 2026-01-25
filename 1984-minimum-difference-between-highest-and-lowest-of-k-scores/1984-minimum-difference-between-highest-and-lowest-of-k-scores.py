class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        # Sort the array in ascending order to group similar values together
        nums.sort()
      
        # Find the minimum difference between max and min in any window of size k
        # We iterate through all possible windows of size k
        # For each window starting at index i, the difference is nums[i+k-1] - nums[i]
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))