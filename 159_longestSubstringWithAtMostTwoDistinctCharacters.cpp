//==============================================================================
// 159. Longest Substring with At Most Two Distinct Characters
// C++
// Tag: String(Hash Table, 2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> tables;
        int left = 0;
        int right = 0;
        int res = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (tables.size() <= 2) {
                tables[s[i]] = i;
                right++;
            }
            if (tables.size() > 2) {
                int leftIndex = s.size();
                for (auto n:tables) {
                    leftIndex = min(leftIndex, n.second);
                }
                tables.erase(s[leftIndex]);
                left = leftIndex + 1;
            }
            res = max(res, right - left);
        }
        
        return res;
    }
};
