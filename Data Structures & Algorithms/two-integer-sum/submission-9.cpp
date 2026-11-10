class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> values;

        for(int i = 0; i < nums.size();i++){
            int missing = target - nums[i];
            if(auto it = values.find(missing); it != values.end()){
                return {it->second, i};
            }
            values.insert({nums[i], i});
        }
    }
};
