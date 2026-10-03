class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet(nums.size());

        for(const auto& n : nums){
            auto ans = mySet.insert(n);
            if(ans.second == false){
                return true;
            }
        }

        return false;
    }
};