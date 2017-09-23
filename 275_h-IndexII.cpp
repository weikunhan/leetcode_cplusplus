//==============================================================================
// 275. H-Index II
// C++
// Tag: Array(without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/h-index/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        
        if (citations.empty()) {
            return res;
        }

        for (int i = citations.size() - 1; i >= 0; --i) {
            int tmp = citations.size() - i;
            if (citations[i] >= tmp) {
                res = tmp;
            } else {
                break;
            }
        }
        
        return res;
    }
};
