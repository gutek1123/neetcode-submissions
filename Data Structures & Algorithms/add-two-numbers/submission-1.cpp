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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummyNode;
        ListNode* navigator = &dummyNode;
        bool carryOver = false;

        ListNode *l1Nav = l1, *l2Nav = l2;

        while(l1Nav != nullptr || l2Nav != nullptr || carryOver){
            int sum = 0;
            if(l1Nav != nullptr){
                sum += l1Nav->val;
                l1Nav = l1Nav->next;
            }
            if(l2Nav != nullptr){
                sum += l2Nav->val;
                l2Nav = l2Nav->next;
            }
            if(carryOver){
                sum ++;
                carryOver = false;
            }
            if(sum >= 10){
                sum = sum % 10;
                carryOver = true;
            }

                navigator->next = new ListNode(sum);
                navigator = navigator->next;
            

        }


        return dummyNode.next;    
    }
    
};
