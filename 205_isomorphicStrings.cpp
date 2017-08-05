//==============================================================================
// 205. Isomorphic Strings
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> tables1;
        unordered_map<char, char> tables2;
        bool res = false;
        
        for (int i = 0; i < s.size(); ++i) {
            char sKey = s[i];
            char tKey = t[i];
            if (tables1.find(sKey) != tables1.end() && tables1[sKey] != tKey) {
                return res;
            }
            if (tables2.find(tKey) != tables2.end() && tables2[tKey] != sKey) {
                return res;
            }
            tables1[sKey] = tKey;
            tables2[tKey] = sKey;
        }
        
        return res = true;
    }
};
