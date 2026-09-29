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
    bool isValidBST(TreeNode* root) {
        std::pair<int, int> res{INT_MAX, INT_MIN};
        
        return isValid(root,res);
        
    }

    bool isValid(TreeNode* toCheck, std::pair<int, int>& result) {
        if (toCheck->left == nullptr && toCheck->right == nullptr) {
            result.first = toCheck->val;
            result.second = toCheck->val;
            return true;
        }

        std::pair<int, int> leftRange{INT_MAX, INT_MIN};
        std::pair<int, int> rightRange{INT_MAX, INT_MIN};

        if (toCheck->left != nullptr) {
            
            if(isValid(toCheck->left, leftRange) == false){
                return false;
            }
            
            if(leftRange.second >= toCheck->val){
                return false;
            }
        }

        if(toCheck->right != nullptr){
            
            if(isValid(toCheck->right, rightRange) == false){
                return false;
            }

            if(rightRange.first <= toCheck->val){
                return false;
            }

        }

        result.first = std::min(std::min(leftRange.first, rightRange.first), toCheck->val);

        result.second = std::max(std::max(leftRange.second, rightRange.second), toCheck->val);

        return true;

    }
};
