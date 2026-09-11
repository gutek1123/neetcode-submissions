class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> multiplicationTableOnLeft(nums.size(), 1);
        std::vector<int> multiplicationTableOnRight(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            multiplicationTableOnLeft[i] = multiplicationTableOnLeft[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            multiplicationTableOnRight[i] = multiplicationTableOnRight[i + 1] * nums[i + 1];
        }

        std::vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            result[i] = multiplicationTableOnLeft[i] * multiplicationTableOnRight[i];
        }

        return result;
    }
};
