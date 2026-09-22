class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int xorRes = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            xorRes ^= i;
            xorRes ^= nums[i];
        }
        xorRes ^= nums.size();
        return xorRes;
    }
};
