//==============================================================================
// 289. Game of Life
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int tmp = 0;
                int length1 = board.size();
                int length2 = board[i].size();
                for (int ii = max(i - 1, 0); ii < min(i + 2, length1); ++ii) {
                    for (int jj = max(j - 1, 0); jj < min(j + 2, length2); ++jj) {
                        if (i != ii || j != jj) {
                            tmp += board[ii][jj] % 10;
                        }
                    }
                }
                if (tmp == 3 || (tmp == 2 && board[i][j] == 1)) {
                    board[i][j] += 10;
                }
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] /= 10;
            }
        }
    }
};
