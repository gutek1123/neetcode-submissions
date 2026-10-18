class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> prerequisitesList(numCourses);

        for (const auto& pre : prerequisites) {
            prerequisitesList[pre[0]].push_back(pre[1]);
        }
        std::vector<int> result(numCourses);
        std::vector<int> visitList(numCourses, 0);  // 0 not visited, 1 during visit, 2 visited
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(visitList, i, prerequisitesList, result)) {
                return {};
            }
        }
        return result;
    }
    bool dfs(std::vector<int>& visitList, int nodeToCheck,
             std::vector<std::vector<int>>& prerequisitesList, std::vector<int>& result) {
        if (visitList[nodeToCheck] == 1) {
            return false;
        }
        if (visitList[nodeToCheck] == 2) {
            return true;
        }

        visitList[nodeToCheck] = 1;

        for (const auto& p : prerequisitesList[nodeToCheck]) {
            if (!dfs(visitList, p, prerequisitesList, result)) {
                return false;
            }
        }
        result.push_back(nodeToCheck);
        visitList[nodeToCheck] = 2;
        return true;
    }
};
