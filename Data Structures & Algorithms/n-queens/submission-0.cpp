class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        std::unordered_set<int> takenColumns;
        std::unordered_set<int> takenDiagonal1;  // /diagonal this way, top left element is 0
        std::unordered_set<int> takenDiagonal2;  //  \diagonal this way,
        std::vector<std::vector<std::string>> mapOfQueens;
        std::vector<std::string> mapOfQueensDuringBuild;

            Backtracking(takenColumns, takenDiagonal1, takenDiagonal2, mapOfQueens, 0, n,
                         mapOfQueensDuringBuild);
                      return mapOfQueens;   
        
    }
    void Backtracking(std::unordered_set<int>& takenColumns,
                      std::unordered_set<int>& takenDiagonal1,
                      std::unordered_set<int>& takenDiagonal2,
                      std::vector<std::vector<std::string>>& mapOfQueens, int rowToAddQueenIn,
                      int n, std::vector<std::string>& mapOfQueensDuringBuild) {
        if (rowToAddQueenIn == n) {
            mapOfQueens.push_back(mapOfQueensDuringBuild);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (takenColumns.count(i)) {
                continue;
            }
            int diag1 = calculateDiag1(rowToAddQueenIn, i);
            if (takenDiagonal1.count(diag1)) {
                continue;
            }
            int diag2 = calculateDiag2(rowToAddQueenIn, i, n);
            if (takenDiagonal2.count(diag2)) {
                continue;
            }
            takenColumns.insert(i);
            takenDiagonal1.insert(diag1);
            takenDiagonal2.insert(diag2);

            std::string myCur(n, '.');

            myCur[i] = 'Q';

            mapOfQueensDuringBuild.push_back(myCur);

            Backtracking(takenColumns, takenDiagonal1, takenDiagonal2, mapOfQueens,
                         rowToAddQueenIn + 1, n, mapOfQueensDuringBuild);

            mapOfQueensDuringBuild.pop_back();
            takenColumns.erase(i);
            takenDiagonal1.erase(diag1);
            takenDiagonal2.erase(diag2);
        }
    }
    int calculateDiag1(int row, int col) { return row + col; }
    int calculateDiag2(int row, int col, int n) { return row - col + n - 1; }
};
