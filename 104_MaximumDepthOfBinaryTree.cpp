//==============================================================================
// 104. Maximum Depth of Binary Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description

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
    int maxDepth(TreeNode* root) {
        int res = 0;
        
        return res = helper(root);
    }
    
private:
    int helper(TreeNode *rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        return max(helper(rootIn->left), helper(rootIn->right)) + 1;
    }
};
