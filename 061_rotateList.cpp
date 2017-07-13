//==============================================================================
// 61. Rotate List
// C++
// Tag: Linked List (2 Pointers)
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
        ListNode *left = head;
        int i = 1; 
        
        if(!head) {
            return res = head;
        }
        
        while(left -> next) {
            left = left -> next;
            ++i;
        }
        
        left -> next = head; 

        if (k %= i) {
            for (int j = 0; j < i - k; ++j) {
                left = left -> next; 
            }
        }

        res = left -> next; 
        left -> next = NULL;
        
        return res;
    }
};
