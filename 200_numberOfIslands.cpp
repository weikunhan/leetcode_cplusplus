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
        if (grid[stepIn1][stepIn2] == '0') {
            return;
        }
        
        grid[stepIn1][stepIn2] = '0';
        
        if (stepIn1 < grid.size() - 1) {
            helper(stepIn1 + 1, stepIn2, grid);
        }
        
        if (stepIn1 > 0) {
            helper(stepIn1 - 1, stepIn2, grid);
        }
        
        if (stepIn2 < grid[stepIn1].size() - 1) {
            helper(stepIn1, stepIn2 + 1, grid);
        }
        
        if (stepIn2 > 0) {
            helper(stepIn1, stepIn2 - 1, grid);
        }
    }
};
