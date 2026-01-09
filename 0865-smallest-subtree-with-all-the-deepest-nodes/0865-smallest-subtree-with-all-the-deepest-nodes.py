# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional, Tuple

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Find the smallest subtree that contains all the deepest nodes in the tree.
      
        Args:
            root: The root of the binary tree
          
        Returns:
            The root of the smallest subtree containing all deepest nodes
        """
      
        def dfs(node: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
            """
            Perform depth-first search to find the subtree with all deepest nodes.
          
            Args:
                node: Current node being processed
              
            Returns:
                A tuple containing:
                - The root of the subtree with all deepest nodes in this branch
                - The depth of the deepest node in this branch
            """
            # Base case: if node is None, return None with depth 0
            if node is None:
                return None, 0
          
            # Recursively process left and right subtrees
            left_subtree, left_depth = dfs(node.left)
            right_subtree, right_depth = dfs(node.right)
          
            # If left subtree is deeper, all deepest nodes are in the left subtree
            if left_depth > right_depth:
                return left_subtree, left_depth + 1
          
            # If right subtree is deeper, all deepest nodes are in the right subtree
            if left_depth < right_depth:
                return right_subtree, right_depth + 1
          
            # If both subtrees have the same depth, current node is the LCA of all deepest nodes
            return node, left_depth + 1
      
        # Return only the node from the tuple (discard the depth)
        return dfs(root)[0]
