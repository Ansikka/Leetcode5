class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        # Handle edge cases: empty list or single string list
        if not A or len(A) <= 1:
            return 0
      
        num_strings = len(A)
        string_length = len(A[0])
        deleted_columns = 0
      
        # Track which pairs of adjacent strings are already sorted
        # If sorted[i] is True, it means A[i] < A[i+1] lexicographically
        sorted_pairs = [False] * num_strings
      
        # Process each column from left to right
        for col in range(string_length):
            # Check if current column should be deleted
            # A column must be deleted if it breaks the sorting order
            should_delete = False
          
            for row in range(num_strings - 1):
                # Only check pairs that aren't already determined to be sorted
                if not sorted_pairs[row] and A[row][col] > A[row + 1][col]:
                    # Column breaks sorting order, must delete it
                    deleted_columns += 1
                    should_delete = True
                    break  # Skip to next column
          
            # If column was deleted, continue to next column
            if should_delete:
                continue
          
            # Column is valid, update sorted status for string pairs
            # Mark pairs as sorted if current column makes them strictly increasing
            for row in range(num_strings - 1):
                if A[row][col] < A[row + 1][col]:
                    sorted_pairs[row] = True
      
        return deleted_columns