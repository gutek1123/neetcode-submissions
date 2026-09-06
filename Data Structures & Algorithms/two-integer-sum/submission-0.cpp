class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> missingValMap;

        for (int i = 0; i < nums.size(); i++) {
            int missingValue = target - nums[i];
            if (auto it = missingValMap.find(missingValue); it != missingValMap.end()) {
                return {it->second, i};
            }
            missingValMap.insert({nums[i], i});
        }
        return {};
    }
};
