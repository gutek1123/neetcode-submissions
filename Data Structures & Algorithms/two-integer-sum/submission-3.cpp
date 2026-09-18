class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> myMap;

        for (int i = 0; i < nums.size(); i++) {
            if (auto it = myMap.find(target - nums[i]); it != myMap.end()) {
                return {it->second, i};
            }
            myMap.insert({nums[i], i});
        }
    }
};
