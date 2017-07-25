//==============================================================================
// 108. Convert Sorted Array to Binary Search Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *res = NULL;
        
        return res = helper(0, nums.size() - 1, nums);
    }
    
private:
    TreeNode* helper(int minIn, int maxIn, vector<int> &number) {
        if (minIn > maxIn) { 
            return NULL; 
        }
        
        int index = (minIn + maxIn) / 2;
        TreeNode* root = new TreeNode(number[index]);
        root->left = helper(minIn, index - 1, number);
        root->right = helper(index + 1, maxIn, number);
        
        return root;
    }
};
