class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        long sum = 0;

        for (const auto& n : nums) {
            sum += n;
        }

        int size = nums.size();
        long expectedSum = ((long)size * (size + 1)) / 2;
        return expectedSum - sum;
    }
};
