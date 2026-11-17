class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> values;
        for(const auto& n : nums){
            if(values.count(n)){
                return true;
            }
            values.insert(n);
        }
        return false;
    }
};