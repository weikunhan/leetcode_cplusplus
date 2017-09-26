//==============================================================================
// 290. Word Pattern
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> tables1;
        unordered_set<string> tables2;
        stringstream ss(str);
        string tmp;
        int index = 0;
        bool res = false; 
        
        while (getline(ss, tmp, ' ') && index <= pattern.size()) {
            if (tables1.find(pattern[index]) != tables1.end() && tables1[pattern[index]] != tmp) {
                return res;
            }
            if (tables1.find(pattern[index]) == tables1.end() && tables2.count(tmp) > 0) {
                return res;
            }
            tables1[pattern[index++]] = tmp;
            tables2.insert(tmp);
        }
        
        return res = index == pattern.size();
    }
};
