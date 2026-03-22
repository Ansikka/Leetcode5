class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        """
        Determines if matrix 'mat' can be rotated (0, 90, 180, or 270 degrees) to match 'target'.
      
        Args:
            mat: Source matrix to rotate
            target: Target matrix to match
          
        Returns:
            True if mat can be rotated to match target, False otherwise
        """
      
        def rotate_90_clockwise(matrix: List[List[int]]) -> None:
            """
            Rotates the matrix 90 degrees clockwise in-place using a layer-by-layer approach.
          
            Args:
                matrix: Square matrix to rotate in-place
            """
            n = len(matrix)
          
            # Process the matrix layer by layer from outside to inside
            for layer in range(n // 2):
                # Define the boundaries of the current layer
                first = layer
                last = n - 1 - layer
              
                # Rotate elements in the current layer
                for i in range(first, last):
                    # Calculate offset from the start of the layer
                    offset = i - first
                  
                    # Save top element
                    temp = matrix[first][i]
                  
                    # Move left to top
                    matrix[first][i] = matrix[last - offset][first]
                  
                    # Move bottom to left
                    matrix[last - offset][first] = matrix[last][last - offset]
                  
                    # Move right to bottom
                    matrix[last][last - offset] = matrix[i][last]
                  
                    # Move top (saved) to right
                    matrix[i][last] = temp
      
        # Check all four possible rotations (0°, 90°, 180°, 270°)
        for rotation_count in range(4):
            # Check if current orientation matches target
            if mat == target:
                return True
          
            # Rotate matrix 90 degrees clockwise for next check
            rotate_90_clockwise(mat)
      
        # No rotation matched the target
        return False