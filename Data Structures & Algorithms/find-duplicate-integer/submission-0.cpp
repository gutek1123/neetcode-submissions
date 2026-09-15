class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];

            fast = nums[nums[fast]];

        } while (slow != fast);

        int slowNext = 0;

        do {

            slow = nums[slow];

            slowNext = nums[slowNext];

        }while(slow != slowNext);

        return slow;
    }
};
