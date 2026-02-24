# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        """
        Calculate the sum of all root-to-leaf paths where each path represents a binary number.
      
        Args:
            root: The root node of the binary tree
          
        Returns:
            The sum of all root-to-leaf binary numbers
        """
      
        def dfs(node: TreeNode, current_value: int) -> int:
            """
            Depth-first search to traverse the tree and calculate path sums.
          
            Args:
                node: Current node in the traversal
                current_value: The accumulated binary value from root to current node
              
            Returns:
                Sum of all binary numbers from this subtree
            """
            # Base case: if node is None, contribute 0 to the sum
            if node is None:
                return 0
          
            # Shift current value left by 1 bit and add current node's value
            # This effectively appends the current bit to the binary number
            current_value = (current_value << 1) | node.val
          
            # If this is a leaf node, return the accumulated binary value
            if node.left is None and node.right is None:
                return current_value
          
            # Recursively calculate sum for left and right subtrees
            left_sum = dfs(node.left, current_value)
            right_sum = dfs(node.right, current_value)
          
            return left_sum + right_sum
      
        # Start DFS from root with initial binary value of 0
        return dfs(root, 0)      