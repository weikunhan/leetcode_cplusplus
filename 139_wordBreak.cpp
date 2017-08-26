//==============================================================================
// 139. Word Break
// C++
// Tag: String(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> res(n + 1, false);
        res[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (res[j]) {
                    string word = s.substr(j, i - j);
                    for (int k = 0; k < wordDict.size(); ++k) {
                        if (wordDict[k] == word) {
                            res[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return res[n];
    }
};
