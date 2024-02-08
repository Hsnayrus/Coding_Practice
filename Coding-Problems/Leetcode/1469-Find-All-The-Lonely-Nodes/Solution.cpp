#include "myHeader.hpp"
/*
In a binary tree, a lonely node is a node that is the only child of its parent
node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all
lonely nodes in the tree. Return the list in any order.



Example 1:


Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.
Example 2:


Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.
Example 3:



Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
Output: [77,55,33,66,44,22]
Explanation: Nodes 99 and 88 share the same parent. Node 11 is the root.
All other nodes are lonely.


Constraints:

The number of nodes in the tree is in the range [1, 1000].
1 <= Node.val <= 106
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right)
        : val(_val), left(_left), right(_right) {}
};

class Solution {
  public:
    /**
     * Iterative Solution Algo Mk1:
     * If root is empty
     * 	Return empty list
     * Create an integer vector named lonelyNodes
     * Create a stack named nodeStack
     * Push root to it
     * TreeNode * current;
     * Run a while loop until the stack is empty
     * current = nodeStack.top();
     * nodeStack.pop();
     * if(current != nullptr){
     * 	bool left;
     * bool right;
     * if((left = root->left == nullptr)^ (right = root->right == nullptr)){
     * 	if left{
     * 	append right to lonelyNOdes
     * }
     * else
     * 	append left ot lonelyNodes
     * }
     * if(~left){
     * stack.push(left)}
     * if(~right){
     * stack.push(right)}
     * }
     */
    std::vector<int> getLonelyNodes(TreeNode* root) {
        std::vector<int> lonelyNodes;
        if (root != nullptr) {
            std::stack<TreeNode*> nodeStack;
            nodeStack.push(root);
            TreeNode* current;
            bool left;
            bool right;
            while (!nodeStack.empty()) {
                current = nodeStack.top();
                nodeStack.pop();
                if (current != nullptr) {
                    if ((left = current->left == nullptr) ^
                        (right = current->right == nullptr)) {
                        if (left) {
                            lonelyNodes.push_back(current->right->val);
                        } else {
                            lonelyNodes.push_back(current->left->val);
                        }
                    }
                    if (!left) {
                        nodeStack.push(current->left);
                    }
                    if (!right) {
                        nodeStack.push(current->right);
                    }
                }
            }
        }
        return lonelyNodes;
    }
};