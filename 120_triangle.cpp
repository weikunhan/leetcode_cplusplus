//==============================================================================
// 120. Triangle
// C++
// Tag: Array(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/triangle/tabs/description

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> res(n + 1);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                res[j] = triangle[i][j] + min(res[j], res[j + 1]);
            }
        }
        
        return res[0];
    }
};
