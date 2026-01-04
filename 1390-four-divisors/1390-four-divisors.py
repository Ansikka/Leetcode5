class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        """
        Calculate the sum of divisors for all numbers in nums that have exactly 4 divisors.
      
        Args:
            nums: List of integers to check
          
        Returns:
            Sum of all divisors for numbers with exactly 4 divisors
        """
      
        def get_divisor_sum_if_four(number: int) -> int:
            """
            Calculate sum of divisors if the number has exactly 4 divisors, otherwise return 0.
          
            Args:
                number: Integer to check divisors for
              
            Returns:
                Sum of divisors if count is 4, otherwise 0
            """
            # Start with divisor 2 (we'll count 1 and number separately)
            divisor = 2
          
            # Initialize with 1 and the number itself as divisors
            divisor_count = 2
            divisor_sum = number + 1
          
            # Check divisors up to sqrt(number)
            while divisor <= number // divisor:
                if number % divisor == 0:
                    # Found a divisor
                    divisor_count += 1
                    divisor_sum += divisor
                  
                    # Check if the complementary divisor is different
                    if divisor * divisor != number:
                        # Add the complementary divisor (number // divisor)
                        divisor_count += 1
                        divisor_sum += number // divisor
              
                divisor += 1
          
            # Return sum only if exactly 4 divisors found
            return divisor_sum if divisor_count == 4 else 0
      
        # Apply the function to all numbers and sum the results
        return sum(get_divisor_sum_if_four(number) for number in nums)
