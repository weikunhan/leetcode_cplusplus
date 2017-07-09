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
        ListNode *left = head;
        int length = 1; 
        
        if(!head) {
            return res = head;
        }
        
        while(left -> next) {
            left = left -> next;
            length++;
        }
        
        left -> next = head; 

        if (k %= length) {
            for (int i = 0; i < length - k; i++) {
                left = left -> next; 
            }
        }

        res = left -> next; 
        left -> next = NULL;
        
        return res;
    }
};
