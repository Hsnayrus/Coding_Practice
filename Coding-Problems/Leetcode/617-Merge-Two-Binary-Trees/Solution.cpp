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
 * Algorithm Mk1:
 * Create a new TreeNode * named result(as a class member);
 * Create two  TreeNode *s named firstTree and secondTree, assign them to
 * root1 and root2
 * if(firstTree != nullptr){
 * 	result->val += firstTree->val;
 * 	firstTree = firstTree->left;
 * }
 * if(secondTree != nullptr){
 * 	result->val += secondTree->val;
 * 	secondTree = secondTree->left;
 * }
 * result->left = mergeTrees(firstTree, secondTree);
 * result->right = mergeTrees(firstTree, secondTree);
 * return result;
 * ****Doesn't work****
 *
 * What I did to get the resultant graph:
 * root1 = 1, 3, 2; root2 = 2, 1, 3;
 * I first saw if the first is not null
 * I created a new node since that is the case
 * Checked if the first is not null
 * Since the resultant node is already created I added the value this
 * secondTree's node to the resultant's value
 * Since I know that root1 is not null, I can traverse it's left pointer
 * Since I know that root2 is not null, I can traverse it's right pointer
 * root1 = root1->left;
 * root2 = root2->left;
 * Calling the same function to assign to resultant's left;
 *
 *
 * root1 = 3, 5, null; root2 = 1, null, 4
 *
 * Checked if node1 is not null,
 * Created a node for the new graph with node1's value
 * Checked if root2 is not null,
 * Since resultant exists, I do not have to create another node
 * Just added the value of root2 to resultant;
 * result->left = same function(root1->left, root2->left)
 * result->right = same function(root1->right, root2->right)
 *  return result
 *
 * root1 = 5, null, null; root2 = null
 * root1 != null, created result
 * result with value 5
 * root2 is null so do not care.
 * result->left = same function with root1 = null, root2 = null
 *
 * root1 = null, root2 = null
 */
class Solution {

  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};