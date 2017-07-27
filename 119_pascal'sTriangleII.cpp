//==============================================================================
// 119. Pascal's Triangle II
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/pascals-triangle-ii/tabs/description

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
       	res[0] = 1;
        
        for (int i = 0; i <= rowIndex ; ++i) {
            for (int j = i; j > 0; --j) {
	        res[j] = res[j] + res[j-1];
            }
        }
        
        return res;
    }
};
