class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> myNums;
        for(const auto& n : nums){
            if(myNums.count(n)){
                return true;
            }
            myNums.insert(n);
        }
        return false;
    }
};