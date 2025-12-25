class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Sort the happiness array in descending order to prioritize selecting children with highest happiness
        happiness.sort(reverse=True)
      
        # Initialize the total happiness sum
        total_happiness = 0
      
        # Iterate through the first k children (those with highest happiness values)
        for turn_index, happiness_value in enumerate(happiness[:k]):
            # Each selected child's happiness decreases by the number of children selected before them
            adjusted_happiness = happiness_value - turn_index
          
            # Add the adjusted happiness to total (minimum 0 if happiness becomes negative)
            total_happiness += max(adjusted_happiness, 0)
      
        return total_happiness
