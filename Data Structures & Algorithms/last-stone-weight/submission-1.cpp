class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> q;

        for(const auto& s : stones){
            q.push(s);
        }

        while(q.size() > 1){
            int largestStone = q.top();
            q.pop();
            int secondLargest = q.top();
            q.pop();
            largestStone -= secondLargest;
            if(largestStone > 0){
                q.push(largestStone);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
