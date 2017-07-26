//==============================================================================
// 113. Path Sum II
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/path-sum-ii/#/description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> solution;
        
        helper(root, sum, solution, res);
        
        return res;
    }
    
private:
    void helper(TreeNode *rootIn, int sumIn, vector<int> solutionIn, vector<vector<int>> &res) {
        if (!rootIn) {
            return;
        }
        
        solutionIn.push_back(rootIn->val);
        
        if (sumIn == rootIn->val && !rootIn->left && !rootIn->right) {
            res.push_back(solutionIn);
        } 
        
        helper(rootIn->left, sumIn - rootIn->val, solutionIn, res);
        helper(rootIn->right, sumIn - rootIn->val, solutionIn, res);
        solutionIn.pop_back();
    }
};
