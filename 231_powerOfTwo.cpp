//==============================================================================
// 231. Power of Two
// C++
// Tag: Math, Bit Manipulation
//==============================================================================
// Summary:
// https://leetcode.com/problems/power-of-two/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool res = false;
        
        if (n <= 0) {
            return res;
        }
        
        return res = !(n & (n - 1));
    }
};
