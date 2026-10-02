struct OceanRange {
    bool pacific = false;
    bool atlantic = false;
};

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::vector<std::vector<int>> res;

        std::vector<std::vector<OceanRange>> ranges(heights.size(),
                                                    (std::vector<OceanRange>(heights[0].size())));

        for (int i = 0; i < heights[0].size(); i++) {
            OceanBacktracker(ranges, 0, i, heights, true, 0);
            OceanBacktracker(ranges, heights.size() - 1, i, heights, false, 0);
        }

        for (int i = 0; i < heights.size(); i++) {
            OceanBacktracker(ranges, i, 0, heights, true, 0);
            OceanBacktracker(ranges, i, heights[0].size() - 1, heights, false, 0);
        }

        for(int i = 0; i < heights[0].size(); i++){
            for(int j = 0; j < heights.size(); j++){
                if(ranges[j][i].pacific && ranges[j][i].atlantic){
                    res.push_back({j,i});
                }
            }
        }
        return res;
    }

    void OceanBacktracker(std::vector<std::vector<OceanRange>>& ranges, int row, int col,
                         const vector<vector<int>>& heights, bool isPacific, int prevHeight) {
        if (row < 0 || col < 0) {
            return;
        }

        if (col >= heights[0].size()) {
            return;
        }

        if (row >= heights.size()) {
            return;
        }

        if (isPacific) {
            if (ranges[row][col].pacific == true) {
                return;
            }
        } else {
            if (ranges[row][col].atlantic == true) {
                return;
            }
        }

        if (heights[row][col] < prevHeight) {
            return;
        }

        if (isPacific) {
            ranges[row][col].pacific = true;
        } else {
            ranges[row][col].atlantic = true;
        }

        OceanBacktracker(ranges, row + 1, col, heights, isPacific, heights[row][col]);
        OceanBacktracker(ranges, row - 1, col, heights, isPacific, heights[row][col]);
        OceanBacktracker(ranges, row, col + 1, heights, isPacific, heights[row][col]);
        OceanBacktracker(ranges, row, col - 1, heights, isPacific, heights[row][col]);
    }
};
