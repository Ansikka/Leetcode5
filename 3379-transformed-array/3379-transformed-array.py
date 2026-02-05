class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        """
        Constructs a transformed array based on the values in the input array.
      
        For each element at index i with value x:
        - If x > 0: take the element x positions to the right (with wraparound)
        - If x < 0: take the element |x| positions to the left (with wraparound)
        - If x == 0: set the result to 0
      
        Args:
            nums: Input list of integers
          
        Returns:
            Transformed list based on the rules above
        """
        result = []
        n = len(nums)
      
        # Iterate through each element in the input array
        for i, value in enumerate(nums):
            if value == 0:
                # If value is 0, append 0 to result
                result.append(0)
            else:
                # Calculate the target index with wraparound
                # (i + value + n) % n handles both positive and negative offsets
                # Adding n ensures the result is always positive before modulo
                target_index = (i + value + n) % n
                result.append(nums[target_index])
              
        return result