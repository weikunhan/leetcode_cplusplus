//==============================================================================
// 293. Flip Game
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/flip-game/description/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        
        return res;
    }
};
