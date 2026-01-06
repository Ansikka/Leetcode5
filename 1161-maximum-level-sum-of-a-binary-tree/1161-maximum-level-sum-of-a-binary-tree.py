# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
from typing import Optional
from math import inf

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        """
        Find the level with the maximum sum in a binary tree.
        Uses BFS to traverse the tree level by level.
      
        Args:
            root: The root node of the binary tree
          
        Returns:
            The 1-indexed level number with the maximum sum
        """
        # Initialize queue for BFS with root node
        queue = deque([root])
      
        # Track maximum sum found so far
        max_sum = -inf
      
        # Current level number (1-indexed)
        current_level = 0
      
        # Result level with maximum sum
        result_level = 0
      
        # Process each level of the tree
        while queue:
            current_level += 1
          
            # Calculate sum for current level
            level_sum = 0
          
            # Process all nodes at current level
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.popleft()
                level_sum += node.val
              
                # Add children to queue for next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
          
            # Update maximum sum and corresponding level if needed
            if max_sum < level_sum:
                max_sum = level_sum
                result_level = current_level
      
        return result_level
