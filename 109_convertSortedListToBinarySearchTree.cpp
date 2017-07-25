//==============================================================================
// 109. Convert Sorted List to Binary Search Tree
// C++
// Tag: Linked List(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    TreeNode* sortedListToBST(ListNode* head) {
    	TreeNode *res = NULL;
        
        return res = helper(head, NULL);
    }
    
private:
    TreeNode *helper(ListNode *headIn, ListNode *tailIn) {
    	ListNode *mid = headIn;
        ListNode *tmp = headIn;
        
        if (headIn == tailIn) {
    		return NULL;
        }
        
        while (tmp != tailIn && tmp->next != tailIn ) {
    		mid = mid->next;
    		tmp = tmp->next->next;
    	}
    	
        TreeNode *root = new TreeNode(mid->val);
    	root->left = helper(headIn, mid);
    	root->right = helper(mid->next, tailIn);
    	
        return root;
    }
};
