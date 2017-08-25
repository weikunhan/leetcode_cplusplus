//==============================================================================
// 148. Sort List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/sort-list/description/

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
    ListNode* sortList(ListNode* head) {
        ListNode *currentNode = head;
        
        if (!currentNode || !currentNode->next) {
            return currentNode;
        }
        
        ListNode *midNode = helper(currentNode);
        ListNode *midNode2 = midNode->next;
        midNode->next = NULL;
        ListNode *half1 = sortList(currentNode);
        ListNode *half2 = sortList(midNode2);
        
        return helper2(half1, half2);
  }
    
private: 
    ListNode *helper(ListNode *nodeIn) {
        ListNode *left = nodeIn;
        ListNode *right = nodeIn->next;
        
        while (right && right->next) {
            left = left->next;
            right = right->next->next;
        }
        
        return left;
    }
    
    ListNode *helper2(ListNode *nodeIn1, ListNode *nodeIn2) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
    
        while (nodeIn1 && nodeIn2) {
            if (nodeIn1->val < nodeIn2->val) {
                prev->next = nodeIn1;
                nodeIn1 = nodeIn1->next;
            } else {
                prev->next = nodeIn2;
                nodeIn2 = nodeIn2->next;
            }
            prev = prev->next;
        }
    
        if (nodeIn1) {
            prev->next = nodeIn1;
        }
    
        if (nodeIn2) {
            prev->next = nodeIn2;
        }
    
        return dummy->next;
    }
};
