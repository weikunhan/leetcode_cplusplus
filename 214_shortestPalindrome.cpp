//==============================================================================
// 214. Shortest Palindrome
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
public:
    string shortestPalindrome(string s) { 
        vector<int> prefix(2 * s.size() + 1);
        string tmp = s;
        string res;
        reverse(tmp.begin(), tmp.end());
        
        string word = s + "#" + tmp;
        
        for (int i = 1; i < word.size(); ++i) {
            int index = prefix[i - 1];
            while (index > 0 && word[i] != word[index]) {
                index = prefix[index - 1];
            }
            if (word[i] == word[index]) {
                ++index;
            }
            prefix[i] = index;
        }
        
        return res = tmp.substr(0, s.size() - prefix[word.size() - 1]) + s;
    }
};
