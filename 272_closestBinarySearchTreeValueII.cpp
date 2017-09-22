//==============================================================================
// 272. Closest Binary Search Tree Value II
// C++
// Tag: Tree(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> tables1;
        stack<int> tables2;

        helper(root, target, false, tables1);
        helper(root, target, true, tables2);
  
        while (k > 0) {
            if (tables1.empty()) {
                res.push_back(tables2.top());
                tables2.pop();
            } else if (tables2.empty()) {
                res.push_back(tables1.top());
                tables1.pop();
            } else if (abs(tables1.top() - target) < abs(tables2.top() - target)) {
                res.push_back(tables1.top());
                tables1.pop();
            } else {
                res.push_back(tables2.top());
                tables2.pop();
            }
            --k;
        }
  
        return res; 
    }
    
private:
    void helper(TreeNode *rootIn, double targetIn, bool reverseIn, stack<int> &tables) {
        if (!rootIn) {
            return;
        }
        
        helper((reverseIn) ? rootIn->right:rootIn->left, targetIn, reverseIn, tables);

        if ((reverseIn && rootIn->val <= targetIn) || (!reverseIn && rootIn->val > targetIn)) {
            return;
        }

        tables.push(rootIn->val);
        helper((reverseIn) ? rootIn->left:rootIn->right, targetIn, reverseIn, tables);
    }
};
