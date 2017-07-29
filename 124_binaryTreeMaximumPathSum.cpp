//==============================================================================
// 124. Binary Tree Maximum Path Sum
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int res = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        
        return res;  
    }
    
private:
    int helper(TreeNode * rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        int left = max(0, helper(rootIn->left));
        int right = max(0, helper(rootIn->right));
        res = max(res, left + right + rootIn->val);
        
        return max(left, right) + rootIn->val;
    }
};
