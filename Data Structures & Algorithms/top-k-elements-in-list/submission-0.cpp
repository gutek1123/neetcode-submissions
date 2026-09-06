class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> myMap;

        for (const int n : nums) {
            if (auto it = myMap.find(n); it == myMap.end()) {
                myMap.insert({n, 1});
            } else {
                it->second++;
            }
        }

        std::vector<std::vector<int>> myBucket(nums.size() + 1);

        for (const auto& [number, count] : myMap) {
            myBucket[count].push_back(number);
        }

        std::vector<int> result;
        result.reserve(k);
        for (int i = myBucket.size() - 1; i >= 0; i--) {
            while (!myBucket[i].empty() && result.size() < k) {
                result.push_back(myBucket[i].back());
                myBucket[i].pop_back();
            }
            if (result.size() == k) {
                return result;
            }
        }
        return result;
    }
};
