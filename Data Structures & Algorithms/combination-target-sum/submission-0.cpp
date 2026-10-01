class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        BackTracking(nums, target, 0, res, cur);
        return res;
    }

    void BackTracking(const vector<int>& nums, int target, int startIndex,
                      std::vector<std::vector<int>>& result, std::vector<int>& currentCheck) {
        
        int sum = 0;

        for (const auto& n : currentCheck) {
            sum += n;
        }
        
        if(sum == target){
            result.push_back(currentCheck);
            return;
        }

        if(sum > target){
            return;
        }

        for(int i = startIndex; i < nums.size(); i++){
            currentCheck.push_back(nums[i]);
            BackTracking(nums,target,i,result,currentCheck);
            currentCheck.pop_back();
        }
    }
};
