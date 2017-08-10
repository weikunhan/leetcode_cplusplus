//==============================================================================
// 216. Combination Sum III
// C++
// Tag: Array(Backtracking)
//==============================================================================
// Summary:
// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> res;
    	vector<int> solution;
    
    	helper(n, k, 1, solution, res);
    
    	return res;
}

private:
    void helper(int sumIn, int endIn, int startIn, vector<int> solutionIn, vector<vector<int>> &res) {
        if (solutionIn.size() == endIn && sumIn == 0) {
            res.push_back(solutionIn);
            return;
	}
        
	for (int i = startIn; i <= 9; ++i) {
	    solutionIn.push_back(i);
	    helper(sumIn - i, endIn, i + 1, solutionIn, res);
	    solutionIn.pop_back();
	}
    }
};
