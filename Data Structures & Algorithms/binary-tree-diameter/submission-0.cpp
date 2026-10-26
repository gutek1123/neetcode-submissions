/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        backtracker(root, diam);
        return diam;

    }
    int backtracker(TreeNode* node, int& d) {
        if (!node) {
            return 0;
        }
        int left = backtracker(node->left, d);
        int right = backtracker(node->right, d);
        d = std::max(d, left + right);
        return 1 + std::max(left, right);
    }
};
