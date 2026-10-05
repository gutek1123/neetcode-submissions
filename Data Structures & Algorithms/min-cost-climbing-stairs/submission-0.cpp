class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector costVec(cost.size() + 1, 0);
        costVec[1] = cost[0];

        for(int i = 1; i < cost.size(); i++){
            costVec[i + 1] = std::min(costVec[i] + cost[i], costVec[i-1] + cost[i]);
        }
        return std::min(costVec[cost.size()],costVec[cost.size() - 1]);
    }
};
