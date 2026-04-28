class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        # Flatten the grid into a 1D list
        flattened_values = []
      
        # Check if all elements have the same remainder when divided by x
        # Use the first element's remainder as reference
        reference_remainder = grid[0][0] % x
      
        # Iterate through all elements in the grid
        for row in grid:
            for value in row:
                # If any element has a different remainder, it's impossible to make all equal
                if value % x != reference_remainder:
                    return -1
                flattened_values.append(value)
      
        # Sort the flattened values to find the median
        flattened_values.sort()
      
        # Find the median value (middle element for optimal operations)
        median_index = len(flattened_values) // 2
        median_value = flattened_values[median_index]
      
        # Calculate total operations needed to convert all values to the median
        # Each operation changes a value by x, so divide the difference by x
        total_operations = sum(abs(value - median_value) // x for value in flattened_values)
      
        return total_operations