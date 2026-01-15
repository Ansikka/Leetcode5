class Solution:
    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        """
        Calculate the maximum area of a square hole that can be created by removing bars.
      
        Args:
            n: Number of horizontal positions
            m: Number of vertical positions  
            hBars: List of removable horizontal bar positions
            vBars: List of removable vertical bar positions
          
        Returns:
            Maximum area of square hole possible
        """
      
        def find_max_consecutive_gap(bars: List[int]) -> int:
            """
            Find the maximum number of consecutive bars that can be removed.
            Adding 1 accounts for the gap created (e.g., removing bars 2,3 creates gap of size 3).
          
            Args:
                bars: List of bar positions that can be removed
              
            Returns:
                Maximum gap size achievable by removing consecutive bars
            """
            # Sort bars to check consecutive sequences
            bars.sort()
          
            # Track maximum and current consecutive sequence length
            max_consecutive = 1
            current_consecutive = 1
          
            # Iterate through sorted bars to find consecutive sequences
            for i in range(1, len(bars)):
                if bars[i] == bars[i - 1] + 1:
                    # Current bar is consecutive to previous
                    current_consecutive += 1
                    max_consecutive = max(max_consecutive, current_consecutive)
                else:
                    # Reset counter when sequence breaks
                    current_consecutive = 1
          
            # Add 1 to account for the actual gap size
            return max_consecutive + 1
      
        # Find maximum consecutive gaps in both directions
        max_horizontal_gap = find_max_consecutive_gap(hBars)
        max_vertical_gap = find_max_consecutive_gap(vBars)
      
        # Square hole requires equal dimensions, so take minimum and square it
        max_square_side = min(max_horizontal_gap, max_vertical_gap)
        return max_square_side ** 2