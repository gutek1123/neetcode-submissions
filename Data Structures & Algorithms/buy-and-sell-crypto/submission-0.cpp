class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minPriceToBuy = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPriceToBuy = std::min(minPriceToBuy, prices[i]);
            maxProfit = std::max(maxProfit, prices[i] - minPriceToBuy);
        }

        return maxProfit;
    }
};
