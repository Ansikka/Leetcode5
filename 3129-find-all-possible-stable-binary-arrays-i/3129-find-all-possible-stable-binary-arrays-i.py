class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        """
        Count the number of stable arrays with 'zero' zeros and 'one' ones,
        where no more than 'limit' consecutive identical elements are allowed.
      
        Args:
            zero: Number of zeros to place in the array
            one: Number of ones to place in the array
            limit: Maximum consecutive identical elements allowed
          
        Returns:
            Number of valid stable arrays modulo 10^9 + 7
        """
        from functools import cache
      
        MOD = 10**9 + 7
      
        @cache
        def count_arrays(zeros_left: int, ones_left: int, last_element: int) -> int:
            """
            Dynamic programming function to count valid arrays.
          
            Args:
                zeros_left: Remaining zeros to place
                ones_left: Remaining ones to place
                last_element: Last element placed (0 for zero, 1 for one)
              
            Returns:
                Number of valid arrays from this state
            """
            # Base case: no zeros left
            if zeros_left == 0:
                # Valid only if last element was 1 and remaining ones don't exceed limit
                return 1 if (last_element == 1 and ones_left <= limit) else 0
          
            # Base case: no ones left
            if ones_left == 0:
                # Valid only if last element was 0 and remaining zeros don't exceed limit
                return 1 if (last_element == 0 and zeros_left <= limit) else 0
          
            # If last element was 0, we're placing another 0
            if last_element == 0:
                # Add one more 0: sum of all ways to place previous element (0 or 1)
                total_ways = count_arrays(zeros_left - 1, ones_left, 0) + \
                            count_arrays(zeros_left - 1, ones_left, 1)
              
                # Subtract invalid cases where we exceed limit consecutive 0s
                # This happens when we have more than limit consecutive 0s
                if zeros_left - limit - 1 >= 0:
                    total_ways -= count_arrays(zeros_left - limit - 1, ones_left, 1)
              
                return total_ways
          
            # If last element was 1, we're placing another 1
            else:
                # Add one more 1: sum of all ways to place previous element (0 or 1)
                total_ways = count_arrays(zeros_left, ones_left - 1, 0) + \
                            count_arrays(zeros_left, ones_left - 1, 1)
              
                # Subtract invalid cases where we exceed limit consecutive 1s
                # This happens when we have more than limit consecutive 1s
                if ones_left - limit - 1 >= 0:
                    total_ways -= count_arrays(zeros_left, ones_left - limit - 1, 0)
              
                return total_ways
      
        # Calculate total: arrays ending with 0 plus arrays ending with 1
        result = (count_arrays(zero, one, 0) + count_arrays(zero, one, 1)) % MOD
      
        # Clear cache to free memory
        count_arrays.cache_clear()
      
        return result