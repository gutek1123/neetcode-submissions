class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int currentArea = (right - left) * std::min(heights[left], heights[right]);
            maxArea = std::max(maxArea, currentArea);

            if(heights[left] < heights[right]){
                left++;
            }else {
                right--;
            }
        }

        return maxArea;
    }
};
