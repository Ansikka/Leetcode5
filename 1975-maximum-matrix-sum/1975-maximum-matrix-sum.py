class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        min_absolute_value = float('inf')
      
        # Track the sum of absolute values and count of negative numbers
        total_absolute_sum = 0
        negative_count = 0
      
        # Iterate through all elements in the matrix
        for row in matrix:
            for value in row:
                # Count negative numbers
                if value < 0:
                    negative_count += 1
              
                # Get absolute value of current element
                absolute_value = abs(value)
              
                # Update minimum absolute value seen so far
                min_absolute_value = min(min_absolute_value, absolute_value)
              
                # Add to total sum of absolute values
                total_absolute_sum += absolute_value
      
        # If even number of negatives, we can make all values positive
        # If odd number of negatives, one value must remain negative (choose the smallest)
        if negative_count % 2 == 0:
            return total_absolute_sum
        else:
            return total_absolute_sum - 2 * min_absolute_value