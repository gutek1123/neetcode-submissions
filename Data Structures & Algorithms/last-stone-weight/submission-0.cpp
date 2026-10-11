class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for(const auto& stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int biggestStone = maxHeap.top();
            maxHeap.pop();
            int secondBiggestStone = maxHeap.top();
            maxHeap.pop();

            biggestStone = biggestStone - secondBiggestStone;

            if(biggestStone > 0){
                maxHeap.push(biggestStone);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
