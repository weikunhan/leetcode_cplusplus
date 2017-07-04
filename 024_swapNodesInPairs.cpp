//==============================================================================
// 24. Swap Nodes in Pairs
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/swap-nodes-in-pairs/#/description

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *res = head -> next;
        head -> next = swapPairs(res -> next);
        res-> next = head;
        
        return res;
    }
};
