//==============================================================================
// 147. Insertion Sort List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/insertion-sort-list/description/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *current = res->next;
        ListNode *prev = res;

        while (current) {
            if (current->next && current->next->val < current->val) {
                while (prev->next && prev->next->val < current->next->val) {
                    prev = prev->next;
                }
                ListNode *tmp = prev->next;
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = tmp;
                prev = res;
            }
            else {
                current = current->next;
            }
        }

        return res->next;
    }
};
