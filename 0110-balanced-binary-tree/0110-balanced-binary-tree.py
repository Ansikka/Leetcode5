# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
  
from typing import Optional

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        """
        Determines if a binary tree is height-balanced.
        A height-balanced tree is defined as a tree where the depth of the two subtrees 
        of every node never differs by more than 1.
      
        Args:
            root: The root node of the binary tree
          
        Returns:
            True if the tree is balanced, False otherwise
        """
      
        def calculate_height(node: Optional[TreeNode]) -> int:
            """
            Calculates the height of a subtree while checking if it's balanced.
          
            Args:
                node: Current node being processed
              
            Returns:
                The height of the subtree if balanced, -1 if unbalanced
            """
            # Base case: empty node has height 0
            if node is None:
                return 0
          
            # Recursively calculate heights of left and right subtrees
            left_height = calculate_height(node.left)
            right_height = calculate_height(node.right)
          
            # Check if any subtree is unbalanced or if current node violates balance condition
            if (left_height == -1 or 
                right_height == -1 or 
                abs(left_height - right_height) > 1):
                return -1  # Return -1 to indicate unbalanced tree
          
            # Return height of current subtree (1 + maximum height of children)
            return 1 + max(left_height, right_height)
      
        # Tree is balanced if height calculation doesn't return -1
        return calculate_height(root) >= 0
  