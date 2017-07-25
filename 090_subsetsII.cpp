//==============================================================================
// 90. Subsets II
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/subsets-ii/#/description

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> solution;
        sort(nums.begin(), nums.end());
        
        helper(0, solution, nums, res);
        
        return res;
    }
    
private:
    void helper(int startIn, vector<int> solutionIn, vector<int> numberIn, vector<vector<int>> &res) {
        res.push_back(solutionIn);
        
        for (int i = startIn; i < numberIn.size(); ++i) {
            if (i == startIn || numberIn[i] != numberIn[i - 1]) {
                solutionIn.push_back(numberIn[i]);
                helper(i + 1, solutionIn, numberIn, res);
                solutionIn.pop_back();
            }
        }
    }
};
