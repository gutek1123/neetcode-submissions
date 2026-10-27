class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveNum = 0;
        int followerPosition = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                followerPosition = i;
            }else{
                if(nums[followerPosition] == 0){
                    followerPosition = i;
                }
                maxConsecutiveNum = std::max(maxConsecutiveNum, i - followerPosition + 1);
            }
        }
        return maxConsecutiveNum;
    }
};