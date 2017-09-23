//==============================================================================
// 274. H-Index
// C++
// Tag: Array(without Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/h-index/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        sort(citations.begin(), citations.end());
        
        if (citations.empty()) {
            return 0;
        }

        for (int i = citations.size() - 1; i >= 0; --i) {
            int tmp = citations.size() - i;
            if (citations[i] >= tmp && tmp > res) {
                res = tmp;
            } else {
                break;
            }
        }
        
        return res;
    }
};
