//==============================================================================
// 21. Merge Two Sorted Lists
// C++
// Tag: Link List
//==============================================================================
// Summary:
// https://leetcode.com/problems/merge-two-sorted-lists/#/description

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(NULL);
        ListNode *node = res;
        
        while (l1 && l2) {
            if (l1 -> val > l2 -> val) {
                node -> next = l2;
                l2 = l2 -> next;
            } else {
                node -> next = l1;
                l1 = l1 -> next;
            }
            node = node -> next;
        }
        
        node -> next = l1 ? l1:l2;
        
        return res -> next;
    }
};
