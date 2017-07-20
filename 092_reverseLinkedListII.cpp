//==============================================================================
// 92. Reverse Linked List II
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-linked-list-ii/#/description

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* res = new ListNode(0);
        ListNode* prev = res;
        res->next = head;
        
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        
        for (int i = 0; i < n - m; ++i) {
            ListNode* tmp = current->next;
            current->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        
        return res->next;
    }
};
