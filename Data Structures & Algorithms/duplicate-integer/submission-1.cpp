class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet(nums.size());

        for(const auto& n : nums){
            if(mySet.find(n) != mySet.end()){
                return true;
            }
            mySet.insert(n);
        }

        return false;
    }
};