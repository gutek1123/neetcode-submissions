class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> myNumbers(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int missing = target - nums[i];
            if (auto it = myNumbers.find(missing); it != myNumbers.end()) {
                return {it->second, i};
            }
            myNumbers.insert({nums[i], i});
        }
        return {0, 0};
    }
};
