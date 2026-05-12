class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        # Sort tasks by the difference (actual - minimum) in ascending order
        # This ensures we handle tasks with larger "extra" requirements first
        sorted_tasks = sorted(tasks, key=lambda task: task[0] - task[1])
      
        total_initial_effort = 0  # Total initial effort needed
        current_energy = 0  # Current available energy
      
        # Process each task in the sorted order
        for actual_effort, minimum_effort in sorted_tasks:
            # If current energy is less than minimum required to start this task
            if current_energy < minimum_effort:
                # Add the deficit to our total initial effort
                effort_deficit = minimum_effort - current_energy
                total_initial_effort += effort_deficit
                # Update current energy to the minimum required
                current_energy = minimum_effort
          
            # Consume the actual effort for this task
            current_energy -= actual_effort
      
        return total_initial_effort