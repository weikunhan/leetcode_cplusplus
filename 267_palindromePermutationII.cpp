//==============================================================================
// 267. Palindrome Permutation II
// C++
// Tag: Without Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/palindrome-permutation-ii/description/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;  
        map<char, int> tables;  
        string half;
        string mid;
        
        for (int i = 0; i < s.size(); ++i) {
            ++tables[s[i]];
        }
        
        for (auto n:tables) {
            if (n.second % 2 == 1) {
                mid += n.first;
            }
            if (n.second > 1) {
                half += string(n.second / 2, n.first);
            }
        }  
        
        if (mid.size() > 1) {
            return res;
        }
        
        do {  
            string tmp = half;  
            reverse(tmp.begin(), tmp.end());  
            res.push_back(half + mid + tmp);  
        } while (next_permutation(half.begin(), half.end()));  
        
        return res;  
    }
};
