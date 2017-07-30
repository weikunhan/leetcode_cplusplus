//==============================================================================
// 131. Palindrome Partitioning
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> solution;
        
        helper(s, 0, solution, res);
        
        return res;
    }
    
private: 
    void helper(string wordIn, int stepIn, vector<string> solutionIn, vector<vector<string>> &res) {
        if (stepIn == wordIn.size()) {
            res.push_back(solutionIn);
            return;
        }
        
        for (int i = stepIn; i < wordIn.size(); ++i) {
            int left = stepIn;
            int right = i;
            while (left < right && wordIn[left] == wordIn[right]) {
                ++left;
                --right;
            }
            if (left >= right) {
                solutionIn.push_back(wordIn.substr(stepIn, i - stepIn + 1));
                helper(wordIn, i + 1, solutionIn, res);
                solutionIn.pop_back();
            }
        }
    }
};
