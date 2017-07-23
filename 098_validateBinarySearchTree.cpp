//==============================================================================
// 98. Validate Binary Search Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/validate-binary-search-tree/#/description

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
    bool isValidBST(TreeNode* root) {
        bool res = false;
        
        return res = helper(root, NULL, NULL);
    }

private:
    bool helper(TreeNode* rootIn, TreeNode* minIn, TreeNode* maxIn) {
        if (!rootIn) {
            return true;
        }
        
        if ((minIn && rootIn->val <= minIn->val) || (maxIn && rootIn->val >= maxIn->val)) {
            return false;
        }
        
        return helper(rootIn->left, minIn, rootIn) && helper(rootIn->right, rootIn, maxIn);
    }
};
