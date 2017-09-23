//==============================================================================
// 255. Verify Preorder Sequence in Binary Search Tree
// C++
// Tag: Tree(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> tables;
        bool res = false;
        int tmp = INT_MIN;
        
        if (preorder.size() < 2) {
            return res = true;
        }
        
        tables.push(preorder[0]);

        for (int i = 1; i < preorder.size(); ++i) {
            if (tables.empty() || preorder[i] < tables.top()) {
                if (preorder[i] < tmp) {
                    return res;
                }
                tables.push(preorder[i]);
                
            } else {
                while (!tables.empty() && tables.top() < preorder[i]) {
                    tmp = tables.top();
                    tables.pop();
                }
                tables.push(preorder[i]);
            }
        }

        return res = true;
    }
};
