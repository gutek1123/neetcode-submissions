class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    IslandSunker(grid,{i, j});
                }
            }
        }
        return numberOfIslands;
    }

    void IslandSunker(vector<vector<char>>& grid, std::pair<int, int> coordinate) {
        if (coordinate.first < 0 || coordinate.second < 0) {
            return;
        }

        if (coordinate.first >= grid.size() || coordinate.second >= grid[0].size()) {
            return;
        }

        if (grid[coordinate.first][coordinate.second] == '1') {
            grid[coordinate.first][coordinate.second] = '0';
        } else {
            return;
        }

        IslandSunker(grid, {coordinate.first - 1, coordinate.second});
        IslandSunker(grid, {coordinate.first, coordinate.second - 1});
        IslandSunker(grid, {coordinate.first, coordinate.second + 1});
        IslandSunker(grid, {coordinate.first + 1, coordinate.second});
    }
};
