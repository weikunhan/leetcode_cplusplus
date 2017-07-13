//==============================================================================
// 49. Group Anagrams
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// https://leetcode.com/problems/group-anagrams/#/description

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> words;
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); ++i) {
            string word = strs[i]; 
            sort(word.begin(), word.end());
            words[word].insert(strs[i]);
        }
        
        for (auto word:words) { 
            vector<string> anagram = {word.second.begin(), word.second.end()};
            res.push_back(anagram);
        }
        
        return res;
    }
};
