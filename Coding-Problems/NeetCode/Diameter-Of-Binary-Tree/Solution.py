from typing import *
"""
The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.

The length of a path between two nodes in a binary tree is the number of edges between the nodes.

Given the root of a binary tree root, return the diameter of the tree.

Example 1:

Input: root = [1,null,2,3,4,5]

Output: 3

Explanation: 3 is the length of the path [1,2,3,5] or [5,3,2,4].

Example 2:

Input: root = [1,2,3]

Output: 2

Constraints:

    1 <= number of nodes in the tree <= 100
    -100 <= Node.val <= 100

"""
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
Dry run 1st tree: 1, 2, 3, null, null, 5, 4


at any node
the diameter is the max of current max and height(left subtree) + height(right subtree)

left subtree height = 1
right subtree height = 5



Naive intuition:
- If current is not null
- if current == start then find new start in the left  
"""


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0

        def height(node):
            if not node:
                return -1

            left_height = height(node.left)
            right_height = height(node.right)

            current_diameter = left_height + right_height + 2

            self.max_diameter = max(self.max_diameter, current_diameter)

            return 1 + max(left_height, right_height)
        height(root)
        return self.max_diameter


if __name__ == "__main__":
    s1 = Solution()
    print(s1.calculateDiameterOfSubtree(TreeNode(0)))
