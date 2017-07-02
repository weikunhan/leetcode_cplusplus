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
        int i = strs.size();
        int j = 0;
        sort (strs.begin(), strs.end());
        
        if (strs.size() == 0) {
            return res = "";
        } 
        
        while (j < strs[i - 1].size() && strs[0][j] == strs[i - 1][j]) {
            j++;
        }

        return res = strs[0].substr(0, j);
    }
};
