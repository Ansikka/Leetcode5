class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        # Create a set to store all prefixes from arr1
        prefix_set = set()
      
        # Generate all possible prefixes for each number in arr1
        for num in arr1:
            # Keep dividing by 10 to get all prefixes
            # For example: 1234 -> 1234, 123, 12, 1
            while num > 0:
                prefix_set.add(num)
                num //= 10
      
        # Track the maximum length of common prefix found
        max_length = 0
      
        # Check each number in arr2 for common prefixes
        for num in arr2:
            # Generate prefixes for current number by removing digits from right
            while num > 0:
                # If current prefix exists in the set from arr1
                if num in prefix_set:
                    # Update max_length with the length of this common prefix
                    max_length = max(max_length, len(str(num)))
                    # Found longest prefix for this number, no need to check shorter ones
                    break
                # Remove the rightmost digit to get next shorter prefix
                num //= 10
      
        return max_length 