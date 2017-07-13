//==============================================================================
// 51. N-Queens
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/n-queens/#/description

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n, '.'));
        
        helper(n, 0, solution, res);
        
        return res;
    }
    
private:
    void helper(int numberIn, int rowIn, vector<string> solutionIn, vector<vector<string>> &result) {
        if (rowIn == numberIn) {
            result.push_back(solutionIn);
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
