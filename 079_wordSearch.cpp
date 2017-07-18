//==============================================================================
// 79. Word Search
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-search/#/description

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, i, j, word, 0)) {
                    return res = true;
                }
            }
        }
        
        return res;
    }
    
private:
    bool helper(vector<vector<char>> boardIn, int rowIn, int colIn, string wordIn, int startIn) {
        char tmp;
        bool flag = false;
        
        if (boardIn[rowIn][colIn] != wordIn[startIn]) {
            return false;
        }
        
        if (startIn == wordIn.size() - 1) {
            return true;
        }
        
        tmp = boardIn[rowIn][colIn];
        boardIn[rowIn][colIn] = '*';
        
        if (!flag && rowIn > 0) {
            flag = helper(boardIn, rowIn - 1, colIn, wordIn, startIn + 1);
        }
        
        if (!flag && rowIn < boardIn.size() - 1) {
            flag = helper(boardIn, rowIn + 1, colIn, wordIn, startIn + 1);
        }
        
        if (!flag && colIn > 0) {
            flag = helper(boardIn, rowIn, colIn - 1, wordIn, startIn + 1);
        }
        
        if (!flag && colIn < boardIn[0].size() - 1) {
            flag = helper(boardIn, rowIn, colIn + 1, wordIn, startIn + 1); 
        }
        
        boardIn[rowIn][colIn] = tmp;
        
        return flag;
    }
};
