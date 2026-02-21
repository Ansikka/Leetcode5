class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        """
        Count numbers in range [left, right] that have a prime number of set bits.
      
        Args:
            left: Lower bound of the range (inclusive)
            right: Upper bound of the range (inclusive)
          
        Returns:
            Count of integers with prime number of set bits
        """
        # Set of prime numbers up to 19 (maximum possible bit count for 32-bit integers)
        # Since right <= 10^6 < 2^20, we only need primes up to 19
        prime_numbers = {2, 3, 5, 7, 11, 13, 17, 19}
      
        # Count how many numbers have prime number of set bits
        count = 0
        for num in range(left, right + 1):
            # Get the number of set bits (1s) in binary representation
            set_bits_count = num.bit_count()
          
            # Check if the count of set bits is a prime number
            if set_bits_count in prime_numbers:
                count += 1
              
        return count     