//==============================================================================
// 200. Number of Islands
// C++
// Tag: Array(BFS, without DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    helper(i, j, grid);
                }
            }
        }
        
        return res;
    }
    
private:
    void helper(int stepIn1, int stepIn2, vector<vector<char>> &grid) {
        if (stepIn1 < 0 || stepIn2 < 0 || stepIn1 >= grid.size() || stepIn2 >= grid[stepIn1].size() || grid[stepIn1][stepIn2] == '0') {
            return;
        }
        
        grid[stepIn1][stepIn2] = '0';
        helper(stepIn1 + 1, stepIn2, grid);
        helper(stepIn1 - 1, stepIn2, grid);
        helper(stepIn1, stepIn2 + 1, grid);
        helper(stepIn1, stepIn2 - 1, grid);
        
        return;
    }
};
