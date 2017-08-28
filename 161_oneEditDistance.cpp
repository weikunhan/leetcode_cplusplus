//==============================================================================
// 161. One Edit Distance
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/one-edit-distance/description/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        bool res = false;
        int index1 = 0;
        int index2 = 0;
        int difference = 0;
        
        if (s.size() > t.size()) {
            return isOneEditDistance(t, s);
        }
        
        while (index2 < t.size()) {
            if (index1 < s.size() && s[index1] == t[index2]) {
                ++index1;
                ++index2;
            } else {
                ++difference;
                if (s.size() == t.size()) {
                    ++index1;
                }
                ++index2;
            }
        }
        
        return res = difference == 1;
    }
};
