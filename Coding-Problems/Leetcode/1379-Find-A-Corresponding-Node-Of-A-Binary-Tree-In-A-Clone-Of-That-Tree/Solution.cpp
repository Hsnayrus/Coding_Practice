#include "myHeader.hpp"
/*
Given two binary trees original and cloned and given a reference to a node
target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node
and the answer must be a reference to a node in the cloned tree.



Example 1:


Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target
node is a green node from the original tree. The answer is the yellow node from
the cloned tree. Example 2:


Input: tree = [7], target =  7
Output: 7
Example 3:


Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4


Constraints:

The number of nodes in the tree is in the range [1, 104].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.


Follow up: Could you solve the problem if repeated values on the tree are
allowed?
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * Recursive Algo Mk1:
     * If target == nullptr || original == nullptr || cloned == nullptr
     * 	Return nullptr
     * if cloned.val == target.val, is the base condition
     * 	Return cloned
     * Declare a variable, assign it the value of nullptr, call it cloneTarget
     * cloneTarget = Recurse on the left node of cloned
     * // Recurse again if target not found on the left side.
     * if(cloneTarget == nullptr){
     * 	cloneTarget = Recurse on the right node of cloned
     * }
     * return cloneTarget
     */
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {

        if (original == nullptr || cloned == nullptr || target == nullptr) {
            return nullptr;
        }
        // Base Condition
        if (cloned->val == target->val) {
            return cloned;
        }
        TreeNode* clonedTarget = nullptr;
        clonedTarget = getTargetCopy(original, cloned->left, target);
        if (clonedTarget == nullptr) {
            clonedTarget = getTargetCopy(original, cloned->right, target);
        }
        return clonedTarget;
    }
};