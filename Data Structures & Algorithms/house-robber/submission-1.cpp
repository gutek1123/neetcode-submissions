class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }

        if(nums.size() == 2){
            return std::max(nums[0], nums[1]);
        }
        
        int prevprev = nums[0];
        int prev = std::max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            int current = std::max(prevprev + nums[i], prev);
            prevprev = prev;
            prev = current;
        }
        return prev;
    }
};
