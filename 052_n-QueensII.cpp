//==============================================================================
// 52. N-Queens II
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/n-queens-ii/#/description

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> solution(n, string(n, '.'));
        int res = 0;
        
        helper(n, 0, solution, res);
        
        return res;
    }
    
private:
    void helper(int numberIn, int rowIn, vector<string> solutionIn, int &result) {
        if (rowIn == numberIn) {
            ++result;
            return;
        }
        
        for (int i = 0; i < numberIn; ++i) {
            if (helper2(numberIn, rowIn, i, solutionIn)) {
                solutionIn[rowIn][i] = 'Q';
                helper(numberIn, rowIn + 1, solutionIn, result);
                solutionIn[rowIn][i] = '.';
            }
        }
    }
    
    bool helper2(int numberIn2, int rowIn2, int colIn, vector<string> solutionIn2) {
        for (int i = 0; i < rowIn2; ++i) {
            if (solutionIn2[i][colIn] == 'Q') {
                return false;
            }
        }
        
        for (int i = rowIn2 - 1, j = colIn - 1; i >= 0 && j >= 0; --i, --j) {
            if (solutionIn2[i][j] == 'Q') {
                return false;
            }
        }
        
        for (int i = rowIn2 - 1, j = colIn + 1; i >= 0 && j < numberIn2; --i, ++j) {
            if (solutionIn2[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};
