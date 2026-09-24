/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> myMap;
        return CloneNode(node, myMap);
    }

    Node* CloneNode(Node* originalNode, std::unordered_map<Node*, Node*>& myMap) {
        if (originalNode == nullptr) {
            return nullptr;
        }

        if (myMap.find(originalNode) != myMap.end()) {
            return myMap[originalNode];
        }

        Node* clonedNode = new Node(originalNode->val);
        myMap.insert({originalNode, clonedNode});

        for(auto n : originalNode->neighbors){
            clonedNode->neighbors.push_back(CloneNode(n, myMap));
        }

        return clonedNode;
    }
};
