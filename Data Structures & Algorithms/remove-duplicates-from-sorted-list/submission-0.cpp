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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* navigator = head;

        while(navigator != nullptr){
            ListNode* myNextNode = navigator;
            while(myNextNode != nullptr && myNextNode->val == navigator->val){
                myNextNode = myNextNode->next;
            }
            navigator->next = myNextNode;
            navigator = navigator->next;
        }
        return head;
    }
};
