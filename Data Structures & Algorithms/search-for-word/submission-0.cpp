class scopedGuard {
   private:
    static constexpr char replacement = '#';
    char replacedCharacter;
    int _x;
    int _y;
    std::vector<std::vector<char>>& _board;

   public:
    scopedGuard(std::vector<std::vector<char>>& board, int x, int y) : _board(board) {
        replacedCharacter = board[x][y];
        board[x][y] = replacement;
        _x = x;
        _y = y;
    }
    ~scopedGuard() { _board[_x][_y] = replacedCharacter; }
};

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (finder(board, word, 0, j, i) == true) {
                    return true;
                }
            }
        }
        return false;
    }
    bool finder(std::vector<std::vector<char>>& board, std::string word, int searchedCharNumber,
                int x, int y) {
        if (x < 0 || x >= board.size()) {
            return false;
        }

        if (y < 0 || y >= board[0].size()) {
            return false;
        }

        if (board[x][y] != word[searchedCharNumber]) {
            return false;
        }

        if ((word.length() - 1) == searchedCharNumber) {
            return true;
        }

        scopedGuard myCharacter(board, x, y);

        if (finder(board, word, searchedCharNumber + 1, x, y - 1) ||
            finder(board, word, searchedCharNumber + 1, x - 1, y) ||
            finder(board, word, searchedCharNumber + 1, x, y + 1) ||
            finder(board, word, searchedCharNumber + 1, x + 1, y)) {
            return true;
        }
        return false;
    }
};
