MOD = int(1e9 + 7)


class SegmentTreeNode:
    """
    Node for the segment tree that represents a range [left, right].
    Supports lazy propagation for addition and multiplication operations.
    """
    def __init__(self, left: int, right: int):
        self.left_child = None
        self.right_child = None
        self.left_bound = left  # Left boundary of the range
        self.right_bound = right  # Right boundary of the range
        self.mid_point = (left + right) >> 1  # Midpoint for splitting
        self.sum_value = 0  # Sum of all elements in this range
        self.lazy_add = 0  # Lazy propagation value for addition
        self.lazy_multiply = 1  # Lazy propagation value for multiplication


class SegmentTree:
    """
    Segment tree with lazy propagation supporting range addition and multiplication.
    """
    def __init__(self):
        # Initialize root node covering range [1, 100001]
        self.root = SegmentTreeNode(1, int(1e5 + 1))

    def modifyAdd(self, left: int, right: int, increment: int, node: SegmentTreeNode = None) -> None:
        """
        Add 'increment' to all elements in range [left, right].
      
        Args:
            left: Left boundary of the range (inclusive)
            right: Right boundary of the range (inclusive)
            increment: Value to add to each element
            node: Current node in the recursion (defaults to root)
        """
        if left > right:
            return
          
        if node is None:
            node = self.root
          
        # If current node's range is completely within [left, right]
        if node.left_bound >= left and node.right_bound <= right:
            # Update the sum for this range
            range_size = node.right_bound - node.left_bound + 1
            node.sum_value = (node.sum_value + range_size * increment) % MOD
            # Mark for lazy propagation
            node.lazy_add += increment
            return
          
        # Push down lazy values before processing children
        self._push_down(node)
      
        # Recursively update left and right children if they overlap with [left, right]
        if left <= node.mid_point:
            self.modifyAdd(left, right, increment, node.left_child)
        if right > node.mid_point:
            self.modifyAdd(left, right, increment, node.right_child)
          
        # Update current node's value based on children
        self._push_up(node)

    def modifyMul(self, left: int, right: int, multiplier: int, node: SegmentTreeNode = None) -> None:
        """
        Multiply all elements in range [left, right] by 'multiplier'.
      
        Args:
            left: Left boundary of the range (inclusive)
            right: Right boundary of the range (inclusive)
            multiplier: Value to multiply each element by
            node: Current node in the recursion (defaults to root)
        """
        if left > right:
            return
          
        if node is None:
            node = self.root
          
        # If current node's range is completely within [left, right]
        if node.left_bound >= left and node.right_bound <= right:
            # Apply multiplication to sum and lazy values
            node.sum_value = (node.sum_value * multiplier) % MOD
            node.lazy_add = (node.lazy_add * multiplier) % MOD
            node.lazy_multiply = (node.lazy_multiply * multiplier) % MOD
            return
          
        # Push down lazy values before processing children
        self._push_down(node)
      
        # Recursively update left and right children if they overlap with [left, right]
        if left <= node.mid_point:
            self.modifyMul(left, right, multiplier, node.left_child)
        if right > node.mid_point:
            self.modifyMul(left, right, multiplier, node.right_child)
          
        # Update current node's value based on children
        self._push_up(node)

    def query(self, left: int, right: int, node: SegmentTreeNode = None) -> int:
        """
        Query the sum of elements in range [left, right].
      
        Args:
            left: Left boundary of the range (inclusive)
            right: Right boundary of the range (inclusive)
            node: Current node in the recursion (defaults to root)
          
        Returns:
            Sum of elements in the specified range
        """
        if left > right:
            return 0
          
        if node is None:
            node = self.root
          
        # If current node's range is completely within [left, right]
        if node.left_bound >= left and node.right_bound <= right:
            return node.sum_value
          
        # Push down lazy values before querying children
        self._push_down(node)
      
        result = 0
        # Query left and right children if they overlap with [left, right]
        if left <= node.mid_point:
            result = (result + self.query(left, right, node.left_child)) % MOD
        if right > node.mid_point:
            result = (result + self.query(left, right, node.right_child)) % MOD
          
        return result

    def _push_up(self, node: SegmentTreeNode) -> None:
        """
        Update parent node's value based on its children's values.
      
        Args:
            node: Node to update
        """
        node.sum_value = (node.left_child.sum_value + node.right_child.sum_value) % MOD

    def _push_down(self, node: SegmentTreeNode) -> None:
        """
        Push lazy propagation values down to children nodes.
        Creates children if they don't exist.
      
        Args:
            node: Node whose lazy values need to be pushed down
        """
        # Create children nodes if they don't exist
        if node.left_child is None:
            node.left_child = SegmentTreeNode(node.left_bound, node.mid_point)
        if node.right_child is None:
            node.right_child = SegmentTreeNode(node.mid_point + 1, node.right_bound)
          
        left_child = node.left_child
        right_child = node.right_child
      
        # Apply lazy operations if any exist
        if node.lazy_add != 0 or node.lazy_multiply != 1:
            # Apply multiplication first, then addition (order matters!)
            # Formula: new_value = old_value * multiply + range_size * add
          
            # Update left child
            left_range_size = left_child.right_bound - left_child.left_bound + 1
            left_child.sum_value = (left_child.sum_value * node.lazy_multiply + 
                                   left_range_size * node.lazy_add) % MOD
            left_child.lazy_add = (left_child.lazy_add * node.lazy_multiply + node.lazy_add) % MOD
            left_child.lazy_multiply = (left_child.lazy_multiply * node.lazy_multiply) % MOD
          
            # Update right child
            right_range_size = right_child.right_bound - right_child.left_bound + 1
            right_child.sum_value = (right_child.sum_value * node.lazy_multiply + 
                                    right_range_size * node.lazy_add) % MOD
            right_child.lazy_add = (right_child.lazy_add * node.lazy_multiply + node.lazy_add) % MOD
            right_child.lazy_multiply = (right_child.lazy_multiply * node.lazy_multiply) % MOD
          
            # Clear parent's lazy values
            node.lazy_add = 0
            node.lazy_multiply = 1


class Fancy:
    """
    A data structure that supports:
    - Appending integers to the end
    - Adding a value to all existing elements
    - Multiplying all existing elements by a value
    - Getting the value at a specific index
    """
    def __init__(self):
        self.size = 0  # Current number of elements
        self.tree = SegmentTree()

    def append(self, val: int) -> None:
        """
        Append 'val' to the end of the sequence.
      
        Args:
            val: Value to append
        """
        self.size += 1
        # Add the value at position self.size (1-indexed)
        self.tree.modifyAdd(self.size, self.size, val)

    def addAll(self, inc: int) -> None:
        """
        Add 'inc' to all existing elements in the sequence.
      
        Args:
            inc: Value to add to all elements
        """
        self.tree.modifyAdd(1, self.size, inc)

    def multAll(self, m: int) -> None:
        """
        Multiply all existing elements in the sequence by 'm'.
      
        Args:
            m: Multiplier for all elements
        """
        self.tree.modifyMul(1, self.size, m)

    def getIndex(self, idx: int) -> int:
        """
        Get the value at index 'idx' (0-indexed).
      
        Args:
            idx: Index to query (0-indexed)
          
        Returns:
            Value at the given index, or -1 if index is out of bounds
        """
        if idx >= self.size:
            return -1
        # Convert to 1-indexed for the segment tree
        return self.tree.query(idx + 1, idx + 1)


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)