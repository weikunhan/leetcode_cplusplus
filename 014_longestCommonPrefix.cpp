//==============================================================================
// 14. Longest Common Prefix
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/longest-common-prefix/#/description

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int i = strs.size() - 1;
        int j = 0;
        sort (strs.begin(), strs.end());
        
        if (strs.size() == 0) {
            return res = "";
        } 
        
        while (j < strs[i].size() && strs[0][j] == strs[i][j]) {
            j++;
        }

        return res = strs[0].substr(0, j);
    }
};
