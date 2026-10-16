class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> trustedBy(n, 0);
        std::vector<int> trustsTo(n, 0);

        for (const auto& t : trust) {
            trustedBy[t[1] - 1]++;
            trustsTo[t[0] - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (trustedBy[i] == n - 1 && trustsTo[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};