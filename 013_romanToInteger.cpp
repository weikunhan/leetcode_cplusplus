//==============================================================================
// 13. Roman to Integer
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/roman-to-integer/#/description

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> tables = {{'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100},
                                           {'D', 500},
                                           {'M', 1000}};
        int res = 0;
        
        for (int i = 0; i < s.length() - 1; i++) { 
            if (tables[s[i]] < tables[s[i + 1]]) {
                res -= tables[s[i]];
            } else {
                res += tables[s[i]];
            } 
        }
        res += tables[s.back()];
        
        return res;
    }
};
