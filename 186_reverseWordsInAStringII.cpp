//==============================================================================
// 186. Reverse Words in a String II
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-words-in-a-string-ii/description/

class Solution {
public:
    void reverseWords(string &s) {
        int storeIndex = 0;
        reverse(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); ++i) {
            if (!isspace(s[i])) {
                int index = i;
                if (storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                while (index < s.size() && !isspace(s[index])) {
                    ++storeIndex;
                    ++index; 
                }
                reverse(s.begin() + storeIndex - (index - i), s.begin() + storeIndex);
                i = index;
            }
        }
    }
};
