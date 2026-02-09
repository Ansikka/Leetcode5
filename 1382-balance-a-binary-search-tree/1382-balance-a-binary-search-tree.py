# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        """
        Balance a Binary Search Tree by converting it to a sorted array
        and then rebuilding it as a balanced BST.
      
        Args:
            root: The root node of the unbalanced BST
          
        Returns:
            The root node of the balanced BST
        """
      
        def inorder_traversal(node: TreeNode) -> None:
            """
            Perform inorder traversal to collect all node values in sorted order.
          
            Args:
                node: Current node being visited
            """
            if node is None:
                return
          
            # Traverse left subtree
            inorder_traversal(node.left)
          
            # Process current node - add value to sorted list
            sorted_values.append(node.val)
          
            # Traverse right subtree
            inorder_traversal(node.right)
      
        def build_balanced_bst(left_idx: int, right_idx: int) -> TreeNode:
            """
            Build a balanced BST from sorted array using divide and conquer.
          
            Args:
                left_idx: Starting index of the current subarray
                right_idx: Ending index of the current subarray
              
            Returns:
                Root node of the balanced subtree
            """
            # Base case: invalid range
            if left_idx > right_idx:
                return None
          
            # Choose middle element as root to ensure balance
            mid_idx = (left_idx + right_idx) // 2
          
            # Recursively build left subtree from left half
            left_subtree = build_balanced_bst(left_idx, mid_idx - 1)
          
            # Recursively build right subtree from right half
            right_subtree = build_balanced_bst(mid_idx + 1, right_idx)
          
            # Create new node with middle value and attach subtrees
            return TreeNode(sorted_values[mid_idx], left_subtree, right_subtree)
      
        # Step 1: Extract all values from BST in sorted order
        sorted_values = []
        inorder_traversal(root)
      
        # Step 2: Build balanced BST from sorted values
        return build_balanced_bst(0, len(sorted_values) - 1)