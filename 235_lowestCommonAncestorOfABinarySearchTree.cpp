//==============================================================================
// 235. Lowest Common Ancestor of a Binary Search Tree
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res;
        
        return res = helper(root, p, q);
    }

private:
    TreeNode *helper(TreeNode *rootIn, TreeNode *minIn, TreeNode *maxIn) {
        if (minIn->val < rootIn->val && maxIn->val < rootIn->val) {
            return helper(rootIn->left, minIn, maxIn);
        }
        
        if (minIn->val > rootIn->val && maxIn->val > rootIn->val) {
            return helper(rootIn->right, minIn, maxIn);
        }
        
        return rootIn;
    }
};
