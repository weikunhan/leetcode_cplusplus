//==============================================================================
// 99. Recover Binary Search Tree
// C++
// Tag: Tree(DSF)
//==============================================================================
// Summary:
// https://leetcode.com/problems/recover-binary-search-tree/#/description

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
    TreeNode* mistake1 = NULL;
    TreeNode* mistake2 = NULL;
    TreeNode* lastRoot = new TreeNode(INT_MIN);
    
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(mistake1->val, mistake2->val);
    }
    
private:
    void helper(TreeNode* rootIn) {
        if (!rootIn) {
            return;
        }
            
        helper(rootIn->left);
        
        if (!mistake1 && lastRoot->val >= rootIn->val) {
             mistake1 = lastRoot;
        }
    
        if (mistake1 && lastRoot->val >= rootIn->val) {
            mistake2 = rootIn;
        }        
        
        lastRoot = rootIn;

        helper(rootIn->right);
    }
};
