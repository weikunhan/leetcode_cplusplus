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
    int minDepth(TreeNode* root) {
        int res = 0;
        
        return res = helper(root);
    }
    
private:
    int helper(TreeNode *rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        if (!rootIn->left) {
            return helper(rootIn->right) + 1;
        }
        
        if (!rootIn->right) {
            return helper(rootIn->left) + 1;
        }
        
        return min(helper(rootIn->left), helper(rootIn->right)) + 1;
    }
};
