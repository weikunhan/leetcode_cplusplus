//==============================================================================
// 89. Gray Code
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/gray-code/#/description

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        
        for (int i = 0; i < n; ++i) {
            int index = res.size();
            while (index) {
                --index;
                int number = res[index];
                number += (1 << i);
                res.push_back(number);
            }
        }
        
        return res;  
    }
};
