class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = std::numeric_limits<int>::max();
        int bestSell = 0;

        for (const auto& n : prices) {
            
            if (n < bestBuy) {
                bestBuy = n;
                bestSell = 0;
            }
            
            if(n > bestSell){
                bestSell = n;
            }

            maxProfit = std::max(maxProfit, bestSell - bestBuy);
        }
        return maxProfit;
    }
};
