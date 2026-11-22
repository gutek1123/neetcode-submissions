class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> myQueue;

        for (const auto& n : arr) {
            myQueue.push({abs(x - n), n});
            if (myQueue.size() > k) {
                myQueue.pop();
            }
        }

        while (!myQueue.empty()) {
            res.push_back(myQueue.top().second);
            myQueue.pop();
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};