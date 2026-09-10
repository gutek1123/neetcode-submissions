class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::bitset<9>, 9> mySquares;
        std::array<std::bitset<9>, 9> myColumns;
        for (int i = 0; i < 9; i++) {
            std::bitset<9> myRow{0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (myRow.test(board[i][j] - '1')) {
                        return false;
                    }
                    if (myColumns[j].test(board[i][j] - '1')) {
                        return false;
                    }
                    if (mySquares[i / 3 + (j / 3) * 3].test(board[i][j] - '1')) {
                        return false;
                    }
                    myColumns[j].set(board[i][j] - '1');
                    myRow.set(board[i][j] - '1');
                    mySquares[i / 3 + (j / 3) * 3].set(board[i][j] - '1');
                }
            }
        }
        return true;
    }
};
