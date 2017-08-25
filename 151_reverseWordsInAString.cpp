//==============================================================================
// 151. Reverse Words in a String
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (!isspace(s[i])) {
                int index = i;
                if (storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                while (index < s.size() && !isspace(s[index])) { 
                    s[storeIndex++] = s[index++]; 
                }
                reverse(s.begin() + storeIndex - (index - i), s.begin() + storeIndex);
                i = index;
            }
        }
        
        s.erase(s.begin() + storeIndex, s.end());
    }
};
