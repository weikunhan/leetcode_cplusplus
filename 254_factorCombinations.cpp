//==============================================================================
// 254. Factor Combinations
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/factor-combinations/description/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> solution;
        
        helper(n, solution, res);
        
        return res;
    }
    
private:
    void helper(int numberIn, vector<int> solutionIn, vector<vector<int>> &res) {
        int tmp = (solutionIn.empty()) ? 2:solutionIn.back();
        
        while (tmp <= numberIn / tmp){
            if (numberIn % tmp == 0) {
                solutionIn.push_back(tmp);
                solutionIn.push_back(numberIn / tmp);
                res.push_back(solutionIn);
                solutionIn.pop_back();
                helper(numberIn / tmp, solutionIn, res);
                solutionIn.pop_back();
            }
            ++tmp;
        }
    }
};
