//==============================================================================
// 85. Maximal Rectangle
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximal-rectangle/#/description


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = 0;
        
        if (matrix.empty()) {
            return res;
        } else {
            n = matrix[0].size();
        }
        
        int fromLeft[n];
        int fromRight[n];
        int height[n];
        fill_n(fromLeft, n, 0); 
        fill_n(fromRight, n, n); 
        fill_n(height, n, 0);

        for (int i = 0; i < m; ++i) {
            int currentLeft = 0; 
            int currentRight = n; 
            for (int j = 0; j < n; ++j) { 
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j]=0;
                }
            }
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    fromLeft[j] = max(fromLeft[j], currentLeft);
                } else {
                    fromLeft[j] = 0; 
                    currentLeft = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    fromRight[j] = min(fromRight[j], currentRight);
                } else {
                    fromRight[j] = n; 
                    currentRight = j;
                }    
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, (fromRight[j] - fromLeft[j]) * height[j]);
            }
        }
        
        return res;
    }
};
