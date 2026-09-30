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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int counter = 0;
        findKth(root, k, counter, result);
        return result;
    }
    void findKth(TreeNode* node, int k, int& counter, int& result) {
        if (counter == k) {
            return;
        }

        if (node->left != nullptr) {
            findKth(node->left, k, counter, result);
        }

        if (counter == k) {
            return;
        }

        counter++;

        if (counter == k) {
            result = node->val;
        };

        if (node->right != nullptr) {
            findKth(node->right, k, counter, result);
        }
    }
};
