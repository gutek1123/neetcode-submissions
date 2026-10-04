class Solution {
   public:
    int trap(vector<int>& height) {
        int result = 0;

        auto it = std::max_element(height.begin(), height.end());
        int highestSeen = 0;
        auto i = height.begin();
        while (i < it) {
            if (highestSeen < *i) {
                highestSeen = *i;
            }
            result += highestSeen - *i;
            i++;
        }
        highestSeen = 0;
        i = height.end();
        i--;
        while (i > it) {
            if (highestSeen < *i) {
                highestSeen = *i;
            }
            result += highestSeen - *i;
            i--;
        }

        return result;
    }
};
