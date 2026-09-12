class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minPriceToBuy = std::numeric_limits<int>::max();
        int maxProfit = 0;

        for(const auto n : prices){
            minPriceToBuy > n ? minPriceToBuy = n : maxProfit = std::max(maxProfit, n - minPriceToBuy);
        }

        return maxProfit;
    }
};
