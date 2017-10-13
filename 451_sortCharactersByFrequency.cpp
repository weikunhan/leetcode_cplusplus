//==============================================================================
// 451. Sort Characters By Frequency
// C++
// Tag: String(Hash Table, without Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> tables;
        vector<string> bucket(s.size() + 1);
        string res;

        for (int i = 0; i < s.size(); ++i) {
            ++tables[s[i]];
        }
        
        for (auto n:tables) {
            bucket[n.second].append(n.second, n.first);
        }

        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty()) {
                res += bucket[i];
            }
        }
        
        return res;
    }
};
