//==============================================================================
// 294. Flip Game II
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/flip-game-ii/description/

class Solution {
public:
    bool canWin(string s) {
        vector<string> oneMove;
        bool res = false;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                oneMove.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }

        for (int i = 0; i < oneMove.size(); ++i) {
            if (!canWin(oneMove[i])) {
                return res = true;
            }
        }
        
        return res;
    }
};
