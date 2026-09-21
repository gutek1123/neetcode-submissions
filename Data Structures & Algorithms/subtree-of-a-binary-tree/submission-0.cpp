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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* consideredNode = myQueue.front();
            myQueue.pop();

            if (consideredNode == nullptr) {
                continue;
            }

            if (consideredNode->val == subRoot->val) {
                TreeNode* subRootCopy = subRoot;
                if (CheckSubtree(consideredNode, subRootCopy)) {
                    return true;
                }
            }

            myQueue.push(consideredNode->left);
            myQueue.push(consideredNode->right);
        }
        return false;
    }

    bool CheckSubtree(TreeNode* root, TreeNode* subRoot) {
        std::queue<std::pair<TreeNode*, TreeNode*>> myQueue;
        myQueue.push({root, subRoot});

        while (!myQueue.empty()) {
            std::pair<TreeNode*, TreeNode*> consideredPair = myQueue.front();

            myQueue.pop();

            if (consideredPair.first == nullptr && consideredPair.second == nullptr) {
                continue;
            }

            if (consideredPair.first == nullptr && consideredPair.second != nullptr) {
                return false;
            }

            if (consideredPair.first != nullptr && consideredPair.second == nullptr) {
                return false;
            }

            if (consideredPair.first->val != consideredPair.second->val) {
                return false;
            }

            myQueue.push({consideredPair.first->left, consideredPair.second->left});
            myQueue.push({consideredPair.first->right, consideredPair.second->right});
        }
        return true;
    }
};
