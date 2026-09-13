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
    void reorderList(ListNode* head) {

        std::vector<ListNode*> myListInVector;

        ListNode* navigator = head;

        while(navigator != nullptr){
            myListInVector.push_back(navigator);
            navigator = navigator->next;
        }

        int left = 0;
        int right = myListInVector.size() - 1;

        while(left < right){
            myListInVector[left]->next = myListInVector[right];
            left++;

            if(left >= right){
                break;
            }

            myListInVector[right]->next = myListInVector[left];
            right--;
        }

        myListInVector[left]->next = nullptr;

    }
};
