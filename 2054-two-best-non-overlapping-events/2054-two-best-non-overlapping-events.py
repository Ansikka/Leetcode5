class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Sort events by start time
        events.sort()
        n = len(events)

        # max_value_from[i] stores the maximum value from event i to the last event
        max_value_from = [0] * n
        max_value_from[-1] = events[-1][2]

        # Build the max_value_from array from right to left
        for i in range(n - 2, -1, -1):
            max_value_from[i] = max(max_value_from[i + 1], events[i][2])

        max_sum = 0

        # For each event, find the best non-overlapping event that starts after it ends
        for start, end, value in events:
            # Binary search for the first event that starts after current event ends
            # feasible(mid) = events[mid][0] > end (start time > current end time)
            # Pattern: [false, false, ..., true, true, true]
            left, right = 0, n - 1
            first_true_index = -1

            while left <= right:
                mid = (left + right) // 2
                if events[mid][0] > end:  # feasible condition
                    first_true_index = mid
                    right = mid - 1
                else:
                    left = mid + 1

            # If there's a valid non-overlapping event, add its maximum possible value
            current_sum = value
            if first_true_index != -1:
                current_sum += max_value_from[first_true_index]

            # Update the maximum sum
            max_sum = max(max_sum, current_sum)

        return max_sum