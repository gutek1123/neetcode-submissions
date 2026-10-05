
struct DoubleListNode {
   public:
    DoubleListNode(int value, int key) {
        val = value;
        _key = key;
        prev = nullptr;
        next = nullptr;
    }
    DoubleListNode *prev, *next;
    int val;
    int _key;
};

class LRUCache {
   public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = myMap.find(key);

        if (it == myMap.end()) {
            return -1;
        }

        DoubleListNode* myNode = it->second;

        if (myNode == latestNode) {
            return latestNode->val;
        }

        DoubleListNode* leftNode = myNode->prev;
        DoubleListNode* rightNode = myNode->next;

        leftNode->next = rightNode;
        if (myNode != oldestNode) {
            rightNode->prev = leftNode;
        } else {
            oldestNode = leftNode;
        }

        myNode->prev = nullptr;
        myNode->next = latestNode;
        latestNode->prev = myNode;
        latestNode = myNode;

        return latestNode->val;
    }

    void put(int key, int value) {

        if(latestNode == nullptr){
            DoubleListNode* myNode = new DoubleListNode(value, key);
            latestNode = myNode;
            oldestNode = myNode;
            myMap.insert({myNode->_key, latestNode});
            return;
        }

        if (auto it = myMap.find(key); it != myMap.end()) {
            DoubleListNode* myNode = it->second;
            myNode->val = value;

            if (myNode == latestNode) {
                return;
            }
            DoubleListNode* leftNode = myNode->prev;
            DoubleListNode* rightNode = myNode->next;

            leftNode->next = rightNode;
            if (myNode != oldestNode) {
                rightNode->prev = leftNode;
            } else {
                oldestNode = leftNode;
            }

            latestNode->prev = myNode;
            myNode->prev = nullptr;
            myNode->next = latestNode;
            latestNode = myNode;
            // here goes code when we find
            return;
        }

        DoubleListNode* myNode = new DoubleListNode(value, key);
        myNode->prev = nullptr;
        myNode->next = latestNode;
        latestNode->prev = myNode;
        latestNode = myNode;
        myMap.insert({myNode->_key, latestNode});
        if (myMap.size() > cap) {
            DoubleListNode* leftNode = oldestNode->prev;
            myMap.erase(oldestNode->_key);
            leftNode->next = nullptr;
            delete (oldestNode);
            oldestNode = leftNode;
        }
    }

   private:
    int cap;
    std::unordered_map<int, DoubleListNode*> myMap;
    DoubleListNode* latestNode = nullptr;
    DoubleListNode* oldestNode = nullptr;
};

// nullptr<-prev-- latest -> next ... prev <-- oldestNode -next-> nullptr
