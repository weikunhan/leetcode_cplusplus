//==============================================================================
// 106. Construct Binary Tree from Inorder and Postorder Traversal
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/#/description

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* res = NULL;
        
        return res = helper(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }

private:
    TreeNode* helper(int minIn1, int maxIn1, int minIn2, int maxIn2, vector<int> &inorder, vector<int> &postorder) {
        int index = 0;
         
        if (minIn2 > maxIn2) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[maxIn2]);
    
        for (int i = minIn1; i <= maxIn1; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        
        root->left = helper(minIn1, index - 1, minIn2, minIn2 - minIn1 + index - 1, inorder, postorder);
        root->right = helper(index + 1, maxIn1, maxIn2 - maxIn1 + index, maxIn2 - 1, inorder, postorder);
        
        return root;

    }
};
