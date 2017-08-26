//==============================================================================
// 174. Dungeon Game
// C++
// Tag: Array(DP, without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/dungeon-game/description/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> res(m + 1, vector<int>(n + 1, INT_MAX));
        
        res[m][n - 1] = 1;
        res[m - 1][n] = 1;
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int health = min(res[i + 1][j], res[i][j + 1]) - dungeon[i][j];
                res[i][j] = (health <= 0) ? 1:health;
            }
        }
        
        return res[0][0];
    }
};
