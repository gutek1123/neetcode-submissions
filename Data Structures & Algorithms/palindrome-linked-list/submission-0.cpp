/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<ListNode*> myNodes;

        for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next){
            myNodes.push_back(ptr);
        }

        std::size_t left = 0;
        std::size_t right = myNodes.size() - 1;

        while(left < right){
            if(myNodes[left]->val != myNodes[right]->val){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};