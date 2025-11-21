from typing import Optional, List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree(values: List[Optional[int]]) -> Optional[TreeNode]:
    """Build a binary tree from a list (LeetCode style)."""
    if not values:
        return None
    
    root = TreeNode(values[0])
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        # left child
        if values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1
        if i >= len(values):
            break

        # right child
        if values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root


def smallestFromLeaf(root: Optional[TreeNode]) -> str:
    best = ["~"]

    def dfs(node, path):
        if not node:
            return
        
        new_path = chr(node.val + ord('a')) + path
        
        if not node.left and not node.right:
            if new_path < best[0]:
                best[0] = new_path

        dfs(node.left, new_path)
        dfs(node.right, new_path)

    dfs(root, "")
    return best[0]


# --------------------------------------------------------------------
# ✅ PRINT FUNCTION (What you asked for)
# --------------------------------------------------------------------
def print_smallest_string(values: List[Optional[int]]):
    root = build_tree(values)
    result = smallestFromLeaf(root)
    print(result)


# --------------------------------------------------------------------
# Example Usage
# --------------------------------------------------------------------
print_smallest_string([0, 1, 2, 3, 4, 3, 4])      # Output: dba
print_smallest_string([25, 1, 3, 1, 3, 0, 2])    # Output: adz
print_smallest_string([2, 2, 1, None, 1, 0, None, 0])  # Output: abc
