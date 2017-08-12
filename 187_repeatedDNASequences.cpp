//==============================================================================
// 187. Repeated DNA Sequences
// C++
// Tag: Bit Manipulation(Hash table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> tables;
        vector<string> res;
        
        for (int i = 0; i + 10 <= s.size(); ++i) {
            string target = s.substr(i, 10);
            if (tables[target] == 1) {
                res.push_back(target);
            }
            ++tables[target];
        }
        
        return res;
    }
};
