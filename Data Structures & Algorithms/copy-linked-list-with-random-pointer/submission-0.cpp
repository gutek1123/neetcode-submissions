/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, int> myMap;
        std::vector<Node*> myVec;
        Node myNewListDummy(0);

        Node* toTraverseNewList = &myNewListDummy;
        Node* toTraverse = head;

        int counter = 0;
        while (toTraverse != nullptr) {
            myMap.insert({toTraverse, counter});
            toTraverseNewList->next = new Node(toTraverse->val);
            toTraverseNewList = toTraverseNewList->next;
            myVec.push_back(toTraverseNewList);
            toTraverse = toTraverse->next;
            counter++;
        }

        toTraverse = head;
        toTraverseNewList = myNewListDummy.next;
        while (toTraverse != nullptr) {
            if (toTraverse->random != nullptr) {
                auto it = myMap.find(toTraverse->random);
                toTraverseNewList->random = myVec[it->second];
            }

            toTraverse = toTraverse->next;
            toTraverseNewList = toTraverseNewList->next;
        }
        return myNewListDummy.next;
    }
};
