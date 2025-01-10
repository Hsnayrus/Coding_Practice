from typing import *
"""
You are given the root of a binary tree root. Invert the binary tree and return its root.

Example 1:

Input: root = [1,2,3,4,5,6,7]

Output: [1,3,2,7,6,5,4]

Example 2:

Input: root = [3,2,1]

Output: [3,1,2]

Example 3:

Input: root = []

Output: []

Constraints:

    0 <= The number of nodes in the tree <= 100.
    -100 <= Node.val <= 100

"""
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
Algo:
- If the current node is null, return
- swap left and right
- invertTree(root->left)
- invertTree(root->right)
- return root

"""


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return

        stack = [root]
        while len(stack) != 0:
            current = stack.pop()
            temp = current.left
            current.left = current.right
            current.right = temp

            if current.left:
                stack.append(current.left)
            if current.right:
                stack.append(current.right)
        return root
