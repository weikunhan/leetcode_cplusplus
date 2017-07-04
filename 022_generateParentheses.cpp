//==============================================================================
// 22. Generate Parentheses
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/generate-parentheses/#/description

class Solution {  
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    
private: 
    void helper(vector<string> &res, string tmp, int i, int j) {
        if (i == 0 && j == 0) {
            res.push_back(tmp);
            return;
        }
        if (i > 0) {
            helper(res, tmp + "(", i - 1, j + 1);
        }
        if (j > 0) {
            helper(res, tmp + ")", i, j - 1);
        }
    }
};
