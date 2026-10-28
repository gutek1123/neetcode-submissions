class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i].assign(i + 1, 1);
            if (i < 2) {
                continue;
            }

            for (int j = 1; j < res[i].size() - 1; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};