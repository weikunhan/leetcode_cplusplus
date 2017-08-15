//==============================================================================
// 234. Palindrome Linked List
// C++
// Tag: Linked list(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        bool res = false;
        ListNode *currentNode = head;
        
        if (!currentNode || !currentNode->next) {
            return res = true;
        }
        
        ListNode *midNode = helper(currentNode);
        midNode->next = helper2(midNode->next);
        midNode = midNode->next;
        
        while (currentNode && midNode) {
            if (currentNode->val != midNode->val) {
                return res;
            }
            currentNode = currentNode->next;
            midNode = midNode->next;
        }
        
        return res = true;
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
    
    ListNode *helper2(ListNode *nodeIn) {
        ListNode *prev = NULL;
        
        while (nodeIn) {
            ListNode *tmp = nodeIn->next;
            nodeIn->next = prev;
            prev = nodeIn;
            nodeIn = tmp;
            
        }
        
        return prev;
    }
};
