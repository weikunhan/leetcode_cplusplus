//==============================================================================
// 230. Kth Smallest Element in a BST
// C++
// Tag: Tree(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    int kthSmallest(TreeNode* root, int k) {  
        int res = 0;
        
        if (!root) { 
            return res;
        }
        
        int leftSize = helper(root->left);  
        
        if (k == leftSize + 1) {  
            return res = root->val;  
        } else if (leftSize >= k) {  
            return res = kthSmallest(root->left, k);  
        } else {  
            return res = kthSmallest(root->right, k - leftSize - 1);  
        }
    }
    
private:
    int helper(TreeNode* rootIn) {
        if (!rootIn) {
            return 0; 
        }
        
        return helper(rootIn->left) + helper(rootIn->right) + 1;          
    } 
};
