//==============================================================================
// 3. Longest Substring Without Repeating Characters
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> characters;
        int res = 0;
        int left = 0;
       	
        for (int i = 0; i < s.length(); i++) {
            if (characters.find(s[i]) != characters.end()) {
                left = max(characters[s[i]] + 1, left);
            }
            res = max(res, i + 1 - left);
            characters[s[i]] = i;
        }
        
        return res;
    }
};
