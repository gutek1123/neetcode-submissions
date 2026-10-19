class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet;

        for(const auto& n : nums){
            if(mySet.count(n)){
                return true;
            }
            mySet.insert(n);
        }

        return false;
    }
};