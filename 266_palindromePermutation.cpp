//==============================================================================
// 266. Palindrome Permutation
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-permutation/description/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> tables;
        bool res = false;
        
        for (int i = 0; i < s.size(); ++i) {
            if (tables.find(s[i]) == tables.end()) {
                tables[s[i]] = 1;
            } else {
                tables.erase(s[i]);
            }
        }
        
        return res = tables.size() <= 1;
    }
};
