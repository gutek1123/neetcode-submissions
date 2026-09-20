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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()){
            return nullptr;
        }

        int interval = 1;
        int k = lists.size();

        while(interval < k){
            for(int i = 0; i + interval < k; i = i + interval*2){
                lists[i] = Merge2Lists(lists[i], lists[i+interval]);
            }
            interval = interval*2;
        }
        return lists[0];

    }

    ListNode* Merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode dummyNode(0);
        ListNode* navigator = &dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                navigator->next = list1;
                list1 = list1->next;
                navigator = navigator->next;
            } else {
                navigator->next = list2;
                list2 = list2->next;
                navigator = navigator->next;
            }
        }

        if (list1 != nullptr) {
            navigator->next = list1;
        } else {
            navigator->next = list2;
        }

        return dummyNode.next;
    }
};
