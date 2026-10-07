class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int right = nums1.size() - 1;
        int left = m - 1;
        int small = n -1;

        while(small >= 0){
            if(left >= 0 && nums1[left] > nums2[small]){
                nums1[right] = nums1[left];
                right--;
                left--;
            }else{
                nums1[right] = nums2[small];
                small--;
                right--;
            }
        }
    }
};