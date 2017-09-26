//==============================================================================
// 291. Word Pattern II
// C++
// Tag: String(Backtracking)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-pattern-ii/description/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> tables1;
        unordered_set<string> tables2;
        bool res = false;
        
        return res = helper(str, 0, pattern, 0, tables1, tables2);
    }
    
private:
    bool helper(string wordIn1, int stepIn1, string wordIn2, int stepIn2, unordered_map<char, string> &tables1, unordered_set<string> &tables2) {
        if (stepIn1 == wordIn1.size() && stepIn2 == wordIn2.size()) {
            return true;
        }
        
        if (stepIn1 == wordIn1.size() || stepIn2 == wordIn2.size()) {
            return false;
        }
        
        if (tables1.find(wordIn2[stepIn2]) != tables1.end()) {
            string tmp = tables1[wordIn2[stepIn2]];
            if (tmp != wordIn1.substr(stepIn1, tmp.size())) {
                return false;
            }
            return helper(wordIn1, stepIn1 + tmp.size(), wordIn2, stepIn2 + 1, tables1, tables2);
        }
        
        for (int i = stepIn1; i < wordIn1.size(); ++i) {
            string tmp = wordIn1.substr(stepIn1, i - stepIn1 + 1);
            if (tables2.find(tmp) != tables2.end()) {
                continue;
            }
            tables2.insert(tmp);
            tables1[wordIn2[stepIn2]] = tmp;
            if (helper(wordIn1, i + 1, wordIn2, stepIn2 + 1, tables1, tables2)) {
                return true;
            }
            tables2.erase(tmp);
            tables1.erase(wordIn2[stepIn2]);
        }
        
        return false;
    }
};
