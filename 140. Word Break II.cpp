//==============================================================================
// 140. Word Break II
// C++
// Tag: String(DP, Backtracking)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string solution;
        
        if (!helper1(s, wordDict)) {
            return res;
        }
        
        helper2(s, wordDict, 0, solution, res);
        
        return res;
    }
    
private:
    void helper2(string wordIn, vector<string> wordDictIn, int startIn, string solutionIn, vector<string>& res) {
        if (startIn == wordIn.size()) {
            res.push_back(solutionIn.substr(0, solutionIn.size() - 1));
            return;
        }
        
        for (int i = startIn; i < wordIn.size(); ++i) {
            string word = wordIn.substr(startIn, i - startIn + 1);
            for (int j = 0; j < wordDictIn.size(); ++j) {
                if (wordDictIn[j] == word) {
                    solutionIn = solutionIn + word + " ";
                    helper2(wordIn, wordDictIn, i + 1, solutionIn, res);
                    int size = word.size() + 1;
                    for (int k = 0; k < size; ++k) {
                        solutionIn.pop_back();
                    }
                }
            }
        }
    }
    
    bool helper1(string wordIn, vector<string> wordDictIn) {
        int n = wordIn.size();
        vector<bool> res(n + 1, false);
        res[0] = true;
            
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res[j]) {
                    string word = wordIn.substr(j, i - j);
                    for (int k = 0; k < wordDictIn.size(); ++k) {
                        if (wordDictIn[k] == word) {
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
