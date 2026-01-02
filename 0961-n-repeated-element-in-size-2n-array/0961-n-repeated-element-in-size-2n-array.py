class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
         # Set to track elements we've already seen
        seen_elements = set()
      
        # Iterate through each element in the array
        for num in nums:
            # If we've seen this element before, it must be the one repeated N times
            if num in seen_elements:
                return num
          
            # Add the current element to our set of seen elements
            seen_elements.add(num)