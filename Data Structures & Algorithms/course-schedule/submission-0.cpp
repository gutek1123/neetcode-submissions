class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            return false;
        }

        if (preMap[crs].empty()) {
            return true;
        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }

   private:
    std::unordered_map<int, std::vector<int>> preMap;
    std::unordered_set<int> visiting;
};
