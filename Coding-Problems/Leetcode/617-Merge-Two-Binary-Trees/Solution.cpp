#include "myHeader.hpp"
/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two
trees are overlapped while the others are not. You need to merge the two trees
into a new binary tree. The merge rule is that if two nodes overlap, then sum
node values up as the new value of the merged node. Otherwise, the NOT null node
will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.



Example 1:


Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]


Constraints:

The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
/**
 * Dry Run:
 * Checked that root1 is not null
 * Checked that root2 is not null
 * Created a new treenode called result using the default constructor
 * Added the value of 2 + 3 to the new node
 * Created a pair of a pair or TreeNode * and a TreeNode ** named leftIter
 * leftIter.first.first = root1->left(since root1 != nullptr)
 * leftIter.first.second = root2->right(since root1!= nullptr)
 * leftIter.second = &tempResult->left;
 * Created another pair of the same type as above, named rightIter
 * rightIter.first.first = root1->right(since root1 != nullptr)
 * rightIter.first.second = root2->right(since root2 != nullptr)
 * rightIter.second = &tempResult->right;
 *
 * Algo mk3:
 * Check if either tree is null, if it is, return the other one
 * Create a new Node for the new resultant tree
 * Create another node named result, use default constructor
 * Create a stack, nodeStack, of pair of a pair of TreeNode *s and a TreeNode**
 * nodeStack.push(std::make_pair(std::make_pair(root1, root2), &result))
 * Run a loop until the stack is empty
 *
 */
class Solution {

  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {}
};