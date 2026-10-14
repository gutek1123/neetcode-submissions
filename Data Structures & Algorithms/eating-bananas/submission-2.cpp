class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        int result = right;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            long long totalEatingTime = 0;

            for (const auto& n : piles) {
                totalEatingTime += std::ceil(static_cast<double>(n) / middle);
            }

            if (totalEatingTime <= h) {
                result = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return result;
    }
};
