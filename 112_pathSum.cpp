//==============================================================================
// 112. Path Sum
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/path-sum/#/description

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
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        
        return res = helper(root, sum);
    }

private:
    bool helper(TreeNode *rootIn, int sumIn) {
        if (!rootIn) {
            return false;
        }
        
        if (rootIn->val == sumIn && !rootIn->left && !rootIn->right) {
            return true;
        }
        
        return helper(rootIn->left, sumIn - rootIn->val) || helper(rootIn->right, sumIn - rootIn->val);
    }
};
