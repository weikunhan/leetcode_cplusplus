//==============================================================================
// 105. Construct Binary Tree from Preorder and Inorder Traversal
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = NULL;
        
        return res = helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorderIn, vector<int>& inorderIn, int preMinIn, int preMaxIn, int inMinIn, int inMaxIn) {
        int index = 0;
        
        if (preMinIn > preMaxIn) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorderIn[preMinIn]);
    
        for (int i = inMinIn; i <= inMaxIn; ++i) {
            if (inorderIn[i] == root->val) {
                index = i;
                break;
            }
        }
    
        root->left = helper(preorderIn, inorderIn, preMinIn + 1, preMinIn + index - inMinIn, inMinIn, index - 1);
        root->right = helper(preorderIn, inorderIn, preMaxIn - inMaxIn + index + 1, preMaxIn, index + 1, inMaxIn);
        
        return root;
    }
};
