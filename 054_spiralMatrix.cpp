//==============================================================================
// 54. Spiral Matrix
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/spiral-matrix/#/description

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowEnd = matrix.size() - 1;
        int colEnd = 0; 
        int colBegin = 0;
        int rowBegin = 0;
        
        if (matrix.empty()) {
            return res;
        } else {
            colEnd = matrix[0].size() - 1;
        }

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; ++i) {
                res.push_back(matrix[rowBegin][i]);
            }
            ++rowBegin;
            for (int i = rowBegin; i <= rowEnd; ++i) {
                res.push_back(matrix[i][colEnd]);
            }
            --colEnd;
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; --i) {
                    res.push_back(matrix[rowEnd][i]);
                }
            }
            --rowEnd;
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; --i) {
                    res.push_back(matrix[i][colBegin]);
                }
            }
            ++colBegin;
        }
        
        return res;
    }
};
