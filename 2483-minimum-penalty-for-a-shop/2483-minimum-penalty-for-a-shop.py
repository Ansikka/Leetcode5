class Solution:
    def bestClosingTime(self, customers: str) -> int:
        """
        Find the best hour to close the shop to minimize penalty.
        Penalty = number of 'N' hours before closing + number of 'Y' hours after closing
      
        Args:
            customers: String of 'Y' (customer arrives) or 'N' (no customer) for each hour
          
        Returns:
            The optimal closing hour (0 to n inclusive)
        """
        n = len(customers)
      
        # Build prefix sum array for counting 'Y's
        # prefix_sum[i] = number of 'Y's in customers[0:i]
        prefix_sum = [0] * (n + 1)
        for i, customer in enumerate(customers):
            prefix_sum[i + 1] = prefix_sum[i] + (1 if customer == 'Y' else 0)
      
        # Find the closing hour with minimum penalty
        best_hour = 0
        min_penalty = float('inf')
      
        for closing_hour in range(n + 1):
            # Calculate penalty for closing at this hour
            # Penalty before closing: number of 'N's from hour 0 to closing_hour-1
            # = closing_hour - number of 'Y's before closing_hour
            penalty_before = closing_hour - prefix_sum[closing_hour]
          
            # Penalty after closing: number of 'Y's from closing_hour to end
            # = total 'Y's - 'Y's before closing_hour
            penalty_after = prefix_sum[-1] - prefix_sum[closing_hour]
          
            total_penalty = penalty_before + penalty_after
          
            # Update best closing hour if we found a lower penalty
            if total_penalty < min_penalty:
                best_hour = closing_hour
                min_penalty = total_penalty
      
        return best_hour