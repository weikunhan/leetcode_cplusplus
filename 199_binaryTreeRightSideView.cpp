//==============================================================================
// 199. Binary Tree Right Side View
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        helper(root, 1, res);
        
        return res;
    }
    
private:
    void helper(TreeNode *rootIn, int maxIn, vector<int> &res) {
        if (!rootIn) {
            return;
        }
        
        if (maxIn > res.size()) {
            res.push_back(rootIn->val);
        }
        
        helper(rootIn->right, maxIn + 1, res);
        helper(rootIn->left, maxIn + 1, res);
    }
};
