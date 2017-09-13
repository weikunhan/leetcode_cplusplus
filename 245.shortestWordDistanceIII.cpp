//==============================================================================
// 245. Shortest Word Distance III
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/shortest-word-distance-iii/description/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int res = INT_MAX;
        
        if (word1 != word2) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    index1 = i;
                }
                if (words[i] == word2) {
                    index2 = i;
                }
                if (index1 != -1 && index2 != -1) {
                    res = min(res, abs(index1 - index2));
                }
            }
        } else {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    if (index1 == -1) {
                        index1 = i;
                    } else {
                        res = min(res, i - index1);
                        index1 = i;
                    }
                }
            }
        }
        
        return res;    
    }
};
