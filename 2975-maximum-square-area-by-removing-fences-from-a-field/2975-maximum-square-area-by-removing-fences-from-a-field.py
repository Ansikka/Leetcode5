class Solution:
    def maximizeSquareArea(
        self, m: int, n: int, hFences: List[int], vFences: List[int]
    ) -> int:
        """
        Find the maximum square area that can be formed in a field with fences.
      
        Args:
            m: Width of the field
            n: Height of the field
            hFences: List of horizontal fence positions
            vFences: List of vertical fence positions
          
        Returns:
            Maximum square area modulo 10^9 + 7, or -1 if no square can be formed
        """
      
        def get_all_distances(fence_positions: List[int], field_size: int) -> Set[int]:
            """
            Calculate all possible distances between any two fence positions,
            including the field boundaries.
          
            Args:
                fence_positions: List of fence positions
                field_size: Size of the field dimension (width or height)
              
            Returns:
                Set of all possible distances between fence pairs
            """
            # Add field boundaries (1 and field_size) to fence positions
            all_positions = fence_positions + [1, field_size]
            # Sort positions for consistent processing
            all_positions.sort()
          
            # Calculate all possible distances between any two positions
            distances = set()
            for i in range(len(all_positions)):
                for j in range(i + 1, len(all_positions)):
                    distance = all_positions[j] - all_positions[i]
                    distances.add(distance)
          
            return distances
      
        # Modulo value for the result
        MOD = 10**9 + 7
      
        # Get all possible horizontal distances
        horizontal_distances = get_all_distances(hFences, m)
      
        # Get all possible vertical distances
        vertical_distances = get_all_distances(vFences, n)
      
        # Find common distances (these can form squares)
        common_distances = horizontal_distances & vertical_distances
      
        # Get the maximum common distance (largest square side length)
        max_side_length = max(common_distances, default=0)
      
        # Calculate and return the area
        if max_side_length > 0:
            area = (max_side_length ** 2) % MOD
            return area
        else:
            # No square can be formed
            return -1