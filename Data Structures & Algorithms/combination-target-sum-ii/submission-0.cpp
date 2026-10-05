class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> cur;
        backtrack(candidates, res, target, cur, 0, 0);
        return res;
    }

    void backtrack(const std::vector<int>& candidates, std::vector<std::vector<int>>& res,
                   int target, std::vector<int>& cur, int currentIterator, int currentSum) {

        if(currentSum == target){
            res.push_back(cur);
        }

        if(currentSum > target){
            return;
        }

        for (int i = currentIterator; i < candidates.size(); i++) {
            if(i > currentIterator && candidates[i] == candidates[i-1]){
                continue;
            }
            cur.push_back(candidates[i]);
            backtrack(candidates, res, target, cur, i + 1, currentSum + candidates[i]);
            cur.pop_back();
        }
    }
};
