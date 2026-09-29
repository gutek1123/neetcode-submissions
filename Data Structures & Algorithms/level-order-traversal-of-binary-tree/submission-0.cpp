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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> myQueue;

        myQueue.push(root);

        while (!myQueue.empty()) {
            int levelCounter = myQueue.size();
            std::vector<int> resLevel;

            while (levelCounter > 0) {
                TreeNode* node = myQueue.front();
                myQueue.pop();
                
                if(node->left != nullptr){
                    myQueue.push(node->left);
                }

                if(node->right != nullptr){
                    myQueue.push(node->right);
                }
                resLevel.push_back(node->val);
                levelCounter--;
            }
            res.push_back(resLevel);
        }
        return res;
    }
};
