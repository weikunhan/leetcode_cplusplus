//==============================================================================
// 269. Alien Dictionary
// C++
// Tag: Graph
//==============================================================================
// Summary:
// https://leetcode.com/problems/alien-dictionary/description/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        unordered_map<char, multiset<char>> graph;  
        unordered_map<char, int> degree;  
        
        if (words.empty()) {
            return res;
        }
        
        for (int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            for (int j = 0; j < tmp.size(); ++j) {
                degree[tmp[j]] = 0;
            }
        }
        
        for (int i = 1; i < words.size(); i++) {
            int index =0;
            int length1 = words[i-1].size();
            int length2 = words[i].size();
            while (words[i-1][index] == words[i][index]) {
                ++index;
            }
            if (index >= min(length1, length2)) {
                continue;
            } 
            ++degree[words[i][index]];
            graph[words[i-1][index]].insert(words[i][index]);  
        }

        for (int i = 0; i < degree.size(); ++i) {
            char tmp = ' ';
            for (auto n:degree) {
                if (!n.second) { 
                    tmp = n.first; 
                    break; 
                }
            }
            if (tmp == ' ') {
                return res = "";
            }
            res += tmp;
            --degree[tmp];  
            for (auto n:graph[tmp]) {
                --degree[n];
            }
        }
            
        return res;  
    }
};
