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
        ListNode *prev = res;
        res->next = head;
        ListNode *current = prev->next;
        
        while (current && current->next) {
            ListNode* tmp = current->next;
            current->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        
        return res->next;
    }
};
