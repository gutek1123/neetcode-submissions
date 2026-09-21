class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }

        if(nums.size() == 2){
            return std::max(nums[0], nums[1]);
        }
        
        std::vector<int> res;
        
        res.push_back(nums[0]);
        
        res.push_back(std::max(nums[0], nums[1]));

        for(int i = 2; i < nums.size(); i++){
            res.push_back(std::max(res[i - 1], res[i - 2] + nums[i]));
        }

        return res.back();
    }
};
