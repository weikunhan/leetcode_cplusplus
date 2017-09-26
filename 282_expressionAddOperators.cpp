//==============================================================================
// 282. Expression Add Operators
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/expression-add-operators/description/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        
        helper(num, target, 0, 0, 0, "", res);
        
        return res;
    }
    
private:
    void helper(string wordIn, int targetIn, int stepIn, long numberIn1, long numberIn2, string solutionIn, vector<string>& res) {
        if (stepIn == wordIn.size() && numberIn1 == targetIn) {
            res.push_back(solutionIn);
            return;
        }
        
        for (int i = 1; i <= wordIn.size() - stepIn; ++i) {
            string tmp = wordIn.substr(stepIn, i);
            if (i > 1 && tmp[0] == '0') {
                continue;
            }
            long number = stol(tmp);
            if (stepIn == 0) {
                helper(wordIn, targetIn, i, number, number, tmp, res);
                continue;
            }
            helper(wordIn, targetIn, stepIn + i, numberIn1 + number, number, solutionIn + "+" + tmp, res);
            helper(wordIn, targetIn, stepIn + i, numberIn1 - number, -number, solutionIn + "-" + tmp, res);
            helper(wordIn, targetIn, stepIn + i, numberIn1 - numberIn2 + numberIn2 * number, numberIn2 * number, solutionIn + "*" + tmp, res);
        }
    }
};
