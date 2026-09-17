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
    int maxDepth(TreeNode* root) {

        return backTrace(root, 0);

    }

    int backTrace(TreeNode* root, int level){
        
        if(root == nullptr){
            return level;
        }

        return std::max(backTrace(root->left, level + 1), backTrace(root->right, level + 1));

    }

};
