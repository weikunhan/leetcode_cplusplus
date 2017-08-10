//==============================================================================
// 221. Maximal Square
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximal-square/description/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> square;
        int m = matrix.size();
        int n = 0;
        int res = 0;
        
        if (matrix.empty()) {
            return res;
        } else {
            n =  matrix[0].size();
            square = vector<vector<int>>(m, vector<int>(n));
        }
        
        for (int i = 0; i < n; ++i) {
            square[0][i] = matrix[0][i] - '0';
            res = max(res, square[0][i]);
        }
        
        for (int i = 0; i < m; ++i) {
            square[i][0] = matrix[i][0] - '0';
            res = max(res, square[i][0]);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    square[i][j] = min(square[i - 1][j - 1], min(square[i - 1][j], square[i][j - 1])) + 1;
                    res = max(res, square[i][j]);
                }
            }
        }
        
        return res * res;
    }
};
