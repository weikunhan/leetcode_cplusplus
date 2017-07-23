//==============================================================================
// 97. Interleaving String
// C++
// Tag: String(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/interleaving-string/#/description

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();
        vector<vector<bool>> res(m + 1, vector<bool>(n + 1));
            
        if (k != m + n) {
            return res[0][0];
        } else {
            res[0][0] = true;
        }
        
        for (int i = 1; i <= n; ++i) {
            res[0][i] = res[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            res[i][0] = res[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                res[i][j] = (res[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (res[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
            
        return res[m][n];
    }
};
