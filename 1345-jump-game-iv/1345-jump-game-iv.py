class Solution:
    def minJumps(self, arr: List[int]) -> int:
        # Build a graph where each value maps to all its indices in the array
        value_to_indices = defaultdict(list)
        for index, value in enumerate(arr):
            value_to_indices[value].append(index)
      
        # Initialize BFS queue with starting position (index 0)
        queue = deque([0])
        # Track visited indices to avoid revisiting
        visited = {0}
        # Track the number of steps taken
        steps = 0
      
        # BFS to find minimum steps to reach the last index
        while True:
            # Process all nodes at current level
            for _ in range(len(queue)):
                current_index = queue.popleft()
              
                # Check if we've reached the target (last index)
                if current_index == len(arr) - 1:
                    return steps
              
                # Explore all possible next positions:
                # 1. Move one step forward (current_index + 1)
                # 2. Move one step backward (current_index - 1)
                # 3. Jump to any index with the same value
                # Note: pop() is used to avoid revisiting indices with same value
                next_indices = [current_index + 1, current_index - 1]
                same_value_indices = value_to_indices.pop(arr[current_index], [])
              
                for next_index in (*next_indices, *same_value_indices):
                    # Check if next_index is valid and unvisited
                    if 0 <= next_index < len(arr) and next_index not in visited:
                        queue.append(next_index)
                        visited.add(next_index)
          
            # Increment step count after processing current level
            steps += 1