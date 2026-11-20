class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> vals;
        for(const auto& n: nums){
            if(vals.count(n)){
                return true;
            }
            vals.insert(n);
        }
        return false;
    }
};