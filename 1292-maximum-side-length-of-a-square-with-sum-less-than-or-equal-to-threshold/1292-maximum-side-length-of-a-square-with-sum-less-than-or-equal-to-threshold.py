class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        """
        Find the maximum side length of a square with sum <= threshold.
        Uses binary search template to find first infeasible side, then return answer - 1.

        For "find maximum" problems, we search for first side where NOT feasible.
        Pattern: true, true, ..., false, false (find first false, answer is index - 1)
        Reframed: false, false, ..., true, true (find first true where infeasible)
        """
        def feasible(side_length: int) -> bool:
            """Check if there exists a square of given side length with sum <= threshold."""
            for row in range(rows - side_length + 1):
                for col in range(cols - side_length + 1):
                    square_sum = (prefix_sum[row + side_length][col + side_length]
                                 - prefix_sum[row][col + side_length]
                                 - prefix_sum[row + side_length][col]
                                 + prefix_sum[row][col])
                    if square_sum <= threshold:
                        return True
            return False

        rows, cols = len(mat), len(mat[0])

        # Build prefix sum array
        prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
        for i, row in enumerate(mat, start=1):
            for j, value in enumerate(row, start=1):
                prefix_sum[i][j] = (prefix_sum[i - 1][j] + prefix_sum[i][j - 1]
                                   - prefix_sum[i - 1][j - 1] + value)

        # Binary search: find first side_length where NOT feasible (infeasible)
        # Then answer = first_true_index - 1
        left, right = 1, min(rows, cols) + 1  # +1 to include "no valid square" case
        first_true_index = min(rows, cols) + 1  # Default: all sizes are feasible

        while left <= right:
            mid = (left + right) // 2
            if not feasible(mid):  # Infeasible (this is our "true" condition)
                first_true_index = mid
                right = mid - 1  # Look for smaller infeasible
            else:
                left = mid + 1

        # Answer is the largest feasible = first_infeasible - 1
        return first_true_index - 1