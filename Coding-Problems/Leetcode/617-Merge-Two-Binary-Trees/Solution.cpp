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

class Solution {
    TreeNode *mergeTreeWorker(TreeNode *root1, TreeNode *root2,
                              TreeNode *result) {
        TreeNode *firstTree = root1;
        TreeNode *secondTree = root2;
        bool first = firstTree != nullptr;
        bool second = secondTree != nullptr;
        if (first || second) {
            result = new TreeNode();
            if (first) {
                result->val += firstTree->val;
                firstTree = firstTree->left;
            }
            if (second) {
                result->val += secondTree->val;
                secondTree = secondTree->left;
            }
        }
        result->left = mergeTreeWorker(firstTree, secondTree, result->left);
        result->right =
            mergeTreeWorker(root1->right, root2->right, result->right);
        return result;
    }

  public:
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
     */
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        return mergeTreeWorker(root1, root2, nullptr);
    }
};