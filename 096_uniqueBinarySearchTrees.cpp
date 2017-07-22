
//==============================================================================
// 96. Unique Binary Search Trees
// C++
// Tag: Tree(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/unique-binary-search-trees/#/description

class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                res[i] += res[j] * res[i - 1 - j];
            }
        }
        
        return res[n];
    }
};
