class Solution {
   public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        std::vector<std::vector<int>> result;
        result.reserve(nums1.size());

        std::size_t nums1Counter = 0, nums2Counter = 0;

        while (nums1Counter < nums1.size() || nums2Counter < nums2.size()) {
            if (nums1Counter >= nums1.size()) {
                result.push_back(nums2[nums2Counter]);
                nums2Counter++;
            } else if (nums2Counter >= nums2.size()) {
                result.push_back(nums1[nums1Counter]);
                nums1Counter++;
            }else {
                if(nums1[nums1Counter][0] < nums2[nums2Counter][0]){
                    result.push_back(nums1[nums1Counter]);
                    nums1Counter++;
                }else if(nums1[nums1Counter][0] > nums2[nums2Counter][0]){
                    result.push_back(nums2[nums2Counter]);
                    nums2Counter++;
                }else {
                    result.push_back({nums1[nums1Counter][0],nums1[nums1Counter][1] + nums2[nums2Counter][1]});
                    nums1Counter++;
                    nums2Counter++;
                }
            }
        }

        return result;
    }
};
