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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<std::pair<TreeNode*, TreeNode*>> myQueue;

        myQueue.push({p, q});

        while (!myQueue.empty()) {
            std::pair<TreeNode*, TreeNode*> myPair = myQueue.front();

            myQueue.pop();

            if (myPair.first == nullptr && myPair.second == nullptr) {
                continue;
            }

            if (myPair.first == nullptr || myPair.second == nullptr) {
                return false;
            }

            if (myPair.first->val != myPair.second->val) {
                return false;
            }

            myQueue.push({myPair.first->left, myPair.second->left});
            myQueue.push({myPair.first->right, myPair.second->right});
        }
        return true;
    }
};
