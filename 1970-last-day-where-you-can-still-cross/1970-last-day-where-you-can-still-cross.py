class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        def can_cross(day: int) -> bool:
            """Check if it's possible to cross from top to bottom on the given day."""
            grid = [[0] * col for _ in range(row)]

            for i in range(day):
                r, c = cells[i]
                grid[r - 1][c - 1] = 1

            queue = []
            for j in range(col):
                if grid[0][j] == 0:
                    queue.append((0, j))
                    grid[0][j] = 1

            idx = 0
            while idx < len(queue):
                x, y = queue[idx]
                idx += 1

                if x == row - 1:
                    return True

                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    next_x, next_y = x + dx, y + dy
                    if 0 <= next_x < row and 0 <= next_y < col and grid[next_x][next_y] == 0:
                        queue.append((next_x, next_y))
                        grid[next_x][next_y] = 1

            return False

        def feasible(day: int) -> bool:
            """Returns true when crossing is NOT possible (inverted condition)."""
            return not can_cross(day)

        # Binary search for first day where crossing becomes impossible
        left, right = 1, len(cells)
        first_true_index = -1

        while left <= right:
            mid = (left + right) // 2
            if feasible(mid):
                first_true_index = mid
                right = mid - 1
            else:
                left = mid + 1

        # Return the last day where crossing was still possible
        return first_true_index - 1