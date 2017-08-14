//==============================================================================
// 206. Reverse Linked List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* reverseList(ListNode* head) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *current = res->next;
        ListNode *prev = NULL;
        
        while (current) {
            ListNode* tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }
        
        res->next = prev;
        
        return res->next;
    }
};
