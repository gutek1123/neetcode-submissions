class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int ,int> myMap;

        for (int i = 0; i < nums.size(); i++) {
            if (auto it = myMap.find(nums[i]); it != myMap.end()) {
                if (i - it->second <= k) {
                    return true;
                }
            }
            myMap[nums[i]] = i;
        }
        return false;
    }
};