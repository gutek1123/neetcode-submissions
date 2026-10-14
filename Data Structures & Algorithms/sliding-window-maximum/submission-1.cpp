class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> myRes;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::less<std::pair<int, int>>>
            maxHeap;

        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});

            if (i < k - 1) {
                continue;
            }

            while (maxHeap.top().second < i - k + 1) {
                maxHeap.pop();
            }

            myRes.push_back(maxHeap.top().first);
        }
        return myRes;
    }
};
