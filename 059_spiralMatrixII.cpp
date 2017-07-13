//==============================================================================
// 59. Spiral Matrix II
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/spiral-matrix-ii/#/description

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int rowEnd = n - 1;
        int colEnd = n - 1; 
        int colBegin = 0;
        int rowBegin = 0;
        int number = 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; ++i) {
                res[rowBegin][i] = number++;
            }
            ++rowBegin;
            for (int i = rowBegin; i <= rowEnd; ++i) {
                res[i][colEnd] = number++;
            }
            --colEnd;
            for (int i = colEnd; i >= colBegin; --i) {
                res[rowEnd][i] = number++;
            }
            --rowEnd;
            for (int i = rowEnd; i >= rowBegin; --i) {
                res[i][colBegin] = number++;
            }
            ++colBegin;
        }

        return res;
    }

};
