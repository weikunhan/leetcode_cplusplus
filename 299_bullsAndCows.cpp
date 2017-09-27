//==============================================================================
// 299. Bulls and Cows
// C++
// Tag: String(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> tables;
        string res;
        int bull = 0;
        int cow = 0;
        
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                if (tables[secret[i]] < 0) {
                    ++cow;
                }
                if (tables[guess[i]] > 0) {
                    ++cow;
                }
                ++tables[secret[i]];
                --tables[guess[i]];
            }
        }
        
        return res = to_string(bull) + "A" + to_string(cow) + "B";
    }
};
