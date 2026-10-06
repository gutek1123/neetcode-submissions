class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int foundEle = 0;
        for(int i = 0; i < nums.size() - foundEle; i++){
            while(nums[i] == val && i < nums.size() - foundEle){
                std::swap(nums[i], nums[nums.size() - 1 - foundEle]);
                foundEle++;
            }
        }
        return nums.size() - foundEle;
    }
};