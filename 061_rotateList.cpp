//==============================================================================
// 61. Rotate List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/rotate-list/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *res;
        ListNode *first = head;
        int j = 1; 
        
        if(!head) {
            return res = head;
        }
        
        while(first -> next) {
            first = first -> next;
            ++j;
        }
        
        first -> next = head; 

        if (k %= length) {
            for (int i = 0; i < j - k; ++i) {
                first = first -> next; 
            }
        }

        res = first -> next; 
        first -> next = NULL;
        
        return res;
    }
};
