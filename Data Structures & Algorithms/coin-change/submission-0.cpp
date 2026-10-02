class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> change(amount + 1, amount + 1);
        change[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (const auto& coin : coins) {
                int iter = i - coin;
                if (iter >= 0) {
                    change[i] = std::min(change[i], change[iter] + 1);
                }
            }
        }
        return change[amount] == (amount + 1)? -1 : change[amount];
    }
};
