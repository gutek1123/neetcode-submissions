class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }

        return std::max(SubRobber(nums, 0, nums.size() - 2), SubRobber(nums, 1, nums.size() - 1));
    }
    int SubRobber(const std::vector<int>& nums, int startingPos, int lastPos) {
        int prevprev = nums[startingPos];
        int prev = std::max(nums[startingPos + 1], prevprev);
        for (int i = startingPos + 2; i <= lastPos; i++) {
            int current = std::max(nums[i] + prevprev, prev);
            prevprev = prev;
            prev = current;
        }
        return prev;
    }
};
