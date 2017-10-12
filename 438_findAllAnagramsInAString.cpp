//==============================================================================
// 438. Find All Anagrams in a String
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> tables;
        int remain = p.size();
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < p.size(); ++i) {
            ++tables[p[i]];
        }
        
        while (left < s.size()) {
            if (tables[s[left]] > 0) {
                --remain;
            }
            --tables[s[left]];
            while (tables[s[left]] < 0) {
                ++tables[s[right]];
                if (tables[s[right]] > 0) {
                    ++remain;
                }
                ++right;
            }
            if (remain == 0) {
                res.push_back(right);
            }
            ++left;
        }
        
        return res;
    }
};
