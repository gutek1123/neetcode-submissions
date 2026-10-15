class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.assign(numCourses, 0);
        graph.resize(numCourses);

        for (const auto& prereq : prerequisites) {
            graph[prereq[0]].emplace_back(prereq[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int course) {
        if (visited[course] == 1) {
            return false;
        }
        if (visited[course] == 2) {
            return true;
        }

        visited[course] = 1;

        std::vector<int>& singleCourse = graph[course];

        for(const auto& c : singleCourse){
            if(!dfs(c)){
                return false;
            }
        }
        visited[course] = 2;
        return true;

    }

   private:
    std::vector<std::vector<int>> graph;
    std::vector<int> visited;  // 0 no, 1 visiting, 2 visited
};
