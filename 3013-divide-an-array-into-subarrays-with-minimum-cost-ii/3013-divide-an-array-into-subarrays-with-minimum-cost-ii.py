class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        """
        Find the minimum cost by selecting k elements where the first element is always included,
        and subsequent elements must be within 'dist' distance from each other.
      
        Args:
            nums: List of numbers to select from
            k: Number of elements to select
            dist: Maximum distance constraint between consecutive selected elements
      
        Returns:
            Minimum sum of k selected elements
        """
        from sortedcontainers import SortedList
      
        # Helper function to move the largest element from left set to right set
        def move_from_left_to_right():
            nonlocal current_sum
            element = left_set.pop()  # Remove largest element from left set
            current_sum -= element
            right_set.add(element)
      
        # Helper function to move the smallest element from right set to left set
        def move_from_right_to_left():
            nonlocal current_sum
            element = right_set.pop(0)  # Remove smallest element from right set
            left_set.add(element)
            current_sum += element
      
        # Adjust k since the first element is always included
        k -= 1
      
        # Initialize with the first window (elements from index 1 to dist+1)
        # nums[0] is always included, so we start the window from index 1
        current_sum = sum(nums[:dist + 2])  # Sum including nums[0]
        left_set = SortedList(nums[1:dist + 2])  # Window elements (excluding nums[0])
        right_set = SortedList()  # Elements outside the k smallest in current window
      
        # Ensure left_set contains exactly k elements (the k smallest in window)
        while len(left_set) > k:
            move_from_left_to_right()
      
        # Initialize answer with the first window's sum
        min_cost = current_sum
      
        # Slide the window through the rest of the array
        for i in range(dist + 2, len(nums)):
            # Remove the element that's going out of the window
            outgoing_element = nums[i - dist - 1]
            if outgoing_element in left_set:
                left_set.remove(outgoing_element)
                current_sum -= outgoing_element
            else:
                right_set.remove(outgoing_element)
          
            # Add the new element entering the window
            incoming_element = nums[i]
            if left_set and incoming_element < left_set[-1]:
                # If new element is smaller than largest in left_set, add to left_set
                left_set.add(incoming_element)
                current_sum += incoming_element
            else:
                # Otherwise, add to right_set
                right_set.add(incoming_element)
          
            # Rebalance to ensure left_set has exactly k elements
            while len(left_set) < k:
                move_from_right_to_left()
            while len(left_set) > k:
                move_from_left_to_right()
          
            # Update the minimum cost
            min_cost = min(min_cost, current_sum)
      
        return min_cost