class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0 , nums.size() - 1);
        return nums;
    }

    void quickSort(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int randomIndex = std::rand() % (right - left);
        int pivot = nums[randomIndex + left];

        std::swap(nums[right], nums[randomIndex + left]);

        int i = left;
        for (int j = left; j < right; j++) {
            if(nums[j] <= pivot){
                std::swap(nums[i], nums[j]);
                i++;
            }
        }

        std::swap(nums[i], nums[right]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};