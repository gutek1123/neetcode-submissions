class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int xAxis = 0;
        int yAxis = 0;

        while (!islandFound(grid, xAxis, yAxis)) {
            if (!navigateToNextField(grid, xAxis, yAxis)) {
                return 0;
            }
        }

        int perimeter = 0;

        std::queue<std::pair<int, int>> landToConsider;
        std::vector<std::vector<bool>> visitedFields(grid.size(),
                                                     std::vector<bool>(grid[0].size()));

        landToConsider.push({xAxis, yAxis});
        visitedFields[yAxis][xAxis] = true;
        while (!landToConsider.empty()) {
            auto [curX, curY] = landToConsider.front();
            landToConsider.pop();
            std::vector<std::pair<int, int>> adjFields = getAdjacentFields(curX, curY);
            for (const auto& adj : adjFields) {
                if (!isFieldInBounds(grid, adj.first, adj.second) ||
                    grid[adj.second][adj.first] == water) {
                    perimeter++;
                } else {
                    if (visitedFields[adj.second][adj.first] == false) {
                        landToConsider.push(adj);
                        visitedFields[adj.second][adj.first] = true;
                    }
                }
            }
        }
        return perimeter;
    }
    bool islandFound(const std::vector<std::vector<int>>& grid, int x, int y) {
        if (grid[y][x] == land) {
            return true;
        }
        return false;
    }
    bool navigateToNextField(const std::vector<std::vector<int>>& grid, int& x, int& y) {
        if (x < grid[0].size() - 1) {
            x++;
            return true;
        } else if (y < grid.size() - 1) {
            y++;
            x = 0;
            return true;
        }
        return false;
    }
    std::vector<std::pair<int, int>> getAdjacentFields(int x, int y) {
        std::vector<std::pair<int, int>> res;
        res.push_back({x - 1, y});
        res.push_back({x, y - 1});
        res.push_back({x + 1, y});
        res.push_back({x, y + 1});
        return res;
    }
    bool isFieldInBounds(const std::vector<std::vector<int>>& grid, int x, int y) {
        if (x < grid[0].size() && y < grid.size() && x >= 0 && y >= 0) {
            return true;
        }

        return false;
    }

   private:
    static constexpr int land = 1;
    static constexpr int water = 0;
};