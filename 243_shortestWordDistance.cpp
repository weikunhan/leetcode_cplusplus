//==============================================================================
// 243. Shortest Word Distance
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/shortest-word-distance/description/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int position1 = -1;
        int position2 = -1;
        int res = INT_MAX;
    
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                position1 = i;
            }
            if (words[i] == word2) {
                position2 = i;
            }
            if (position1 != -1 && position2 != -1) {
                res = min(res, abs(position1 - position2));
            }
        }

        return res;
    }
};
