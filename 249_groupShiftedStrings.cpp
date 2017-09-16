//==============================================================================
// 249. Group Shifted Strings
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/group-shifted-strings/description/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> tables;
        vector<vector<string>> res;
        
        for (int i = 0; i < strings.size(); ++i) {
            tables[helper(strings[i])].push_back(strings[i]);
        }

        for (auto n:tables) {
            vector<string> group = n.second;
            sort(group.begin(), group.end());
            res.push_back(group);
        }
        
        return res;
    }
    
private:
    string helper(string &wordIn) {
        string tmp;

        for (int i = 1; i < wordIn.size(); ++i) {
            int difference = wordIn[i] - wordIn[i - 1];
            if (difference < 0) {
                difference += 26;
            }
            tmp += 'a' + difference;
        }
        
        return tmp;
    }
};
