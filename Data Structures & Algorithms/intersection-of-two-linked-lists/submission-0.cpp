/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::unordered_set<ListNode*> values;

        for (ListNode* i = headA; i; i = i->next) {
            values.insert(i);
        }

        for (ListNode* i = headB; i; i = i->next) {
            if(values.count(i)){
                return i;
            }
        }
        return 0;
    }
};  