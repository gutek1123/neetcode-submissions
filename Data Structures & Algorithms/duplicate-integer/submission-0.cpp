class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            
            if(myMap.find(nums[i]) != myMap.end()){
                return true;
            }

            myMap.insert({nums[i], i});
        }
        return false;
    }
};