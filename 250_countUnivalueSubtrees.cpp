
//==============================================================================
// 250. Count Univalue Subtrees
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/count-univalue-subtrees/description/

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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
            
        helper(root, res);
        
        return res;
    }

private:
    bool helper(TreeNode *rootIn, int &res) {
        if (!rootIn) {
            return true;
        }
            
        bool leftCount = helper(rootIn->left, res);
        bool rightCount = helper(rootIn->right, res);
            
        if (leftCount && rightCount) {
            if (rootIn->left && rootIn->val != rootIn->left->val) {
                return false;
            }
            if (rootIn->right && rootIn->val != rootIn->right->val) {
                return false;
            }
            ++res;
            return true;
        }
        
        return false;
    }
};
