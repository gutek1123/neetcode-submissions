class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        std::stack<std::pair<int /*height*/, int /*index*/>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!st.empty() && st.top().first > heights[i]) {
                std::pair<int, int> top = st.top();
                int index = top.second;
                int height = top.first;

                int area = height * (i - index);
                maxArea = std::max(area, maxArea);
                start = index;
                st.pop();
            }
            st.push({heights[i], start});
        }

        while (!st.empty()) {
            std::pair<int, int> top = st.top();
            int index = top.second;
            int height = top.first;

            int area = height * (heights.size() - index);
            maxArea = std::max(area, maxArea);
            st.pop();
        }
        return maxArea;
    }
};
