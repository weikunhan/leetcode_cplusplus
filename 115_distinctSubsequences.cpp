//==============================================================================
// 115. Distinct Subsequences
// C++
// Tag: String(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/distinct-subsequences/tabs/description

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<vector<int>> res(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= n; ++i) {
            res[0][i] = 1;
        }
    
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[j - 1] == t[i - 1]) {
                    res[i][j] = res[i - 1][j - 1] + res[i][j - 1];
                } else {
                    res[i][j] = res[i][j - 1];
                }
            }
        }
    
        return res[m][n];
    }
};
