class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        """
        Find the smallest character in letters that is lexicographically greater than target.
        If no such character exists, return the first character in letters (wrap around).

        Args:
            letters: A sorted list of characters in non-decreasing order
            target: The target character to find the next greatest letter for

        Returns:
            The smallest character greater than target, or the first character if none exists
        """
        n = len(letters)
        left, right = 0, n - 1
        first_true_index = -1

        # Binary search to find the first index where letters[mid] > target
        while left <= right:
            mid = (left + right) // 2

            # Feasible condition: is this character greater than target?
            if letters[mid] > target:
                first_true_index = mid  # Record potential answer
                right = mid - 1  # Search left for smaller valid index
            else:
                left = mid + 1  # Search right

        # Handle wrap-around: if no character is greater, return first character
        if first_true_index == -1:
            return letters[0]
        return letters[first_true_index]