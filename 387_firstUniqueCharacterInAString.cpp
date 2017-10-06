//==============================================================================
// 387. First Unique Character in a String
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> tables;
        int res = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            ++tables[s[i]];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (tables[s[i]] == 1) {
                return res = i;
            }
        }
        
        return res= -1;
    }
};
