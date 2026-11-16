class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<float, int>> distance;

        for (int i = 0; i < points.size(); i++) {
            distance.push({CalcDist(points[i][0], points[i][1]), i});

            if (distance.size() > k) {
                distance.pop();
            }
        }
        std::vector<std::vector<int>> res;

        while(!distance.empty()){
            res.push_back(points[distance.top().second]);
            distance.pop();
        }
        return res;
    }
    float CalcDist(int x, int y) {
        float distance = std::sqrt(static_cast<float>(x) * x + static_cast<float>(y) * y);
        return distance;
    }
};
