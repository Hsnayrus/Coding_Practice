#include "myHeader.hpp"
/*
Given the root node of a binary search tree and two integers low and high,
return the sum of values of all nodes with a value in the inclusive range [low,
high].



Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.


Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right)
        : val(_val), left(_left), right(_right) {}
};

class Solution {
    int sum = 0;

  public:
    /**
     * Algo Mk1:
     * Start at the root node
     * If current node is null, return 0
     * If root->val >= low and <= high
     * 	Sum += root->val
     * rangeSumBST on root->left
     * rangeSumBST on root->right
     */
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root != nullptr) {
            if (root->val >= low && root->val <= high) {
                sum += root->val;
            }
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};
int main() {
    Solution s1;
    TreeNode val(5);
    std::cout << s1.rangeSumBST(&val, 0, 5) << std::endl;
    return EXIT_SUCCESS;
}
