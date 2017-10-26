//==============================================================================
// 711. Number of Distinct Islands II
// C++
// Tag: Array(Hash Table, DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/number-of-distinct-islands-ii/description/

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int number = 0;
        set<vector<pair<int, int>>> res;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    helper1(i, j, ++number, grid);
                    res.insert(helper2(tables[number]));
                }
            }
        }
        
        return res.size();
    }
    
private:
    unordered_map<int, vector<pair<int, int>>> tables;
    
    void helper1(int stepIn1, int stepIn2, int numberIn, vector<vector<int>> &grid) {
        if (stepIn1 < 0 || stepIn2 < 0 || stepIn1 >= grid.size() || stepIn2 >= grid[stepIn1].size()) {
            return;
        }
        
        if (grid[stepIn1][stepIn2] != 1) {
            return;
        }
        
        tables[numberIn].push_back({stepIn1, stepIn2});
        grid[stepIn1][stepIn2] = 0;
        helper1(stepIn1 + 1, stepIn2, numberIn, grid);
        helper1(stepIn1, stepIn2 + 1, numberIn, grid);
        helper1(stepIn1 - 1, stepIn2, numberIn, grid);
        helper1(stepIn1, stepIn2 - 1, numberIn, grid);
    }
    
    vector<pair<int, int>> helper2(vector<pair<int, int>> solutionIn) {
        vector<vector<pair<int,int>>> tmp(8);

        for (int i = 0 ; i < solutionIn.size(); ++i) {
            int x = solutionIn[i].first;
            int y = solutionIn[i].second;
            tmp[0].push_back({x, y});
            tmp[1].push_back({x, -y});
            tmp[2].push_back({-x, y});
            tmp[3].push_back({-x, -y});
            tmp[4].push_back({y, -x});
            tmp[5].push_back({-y, x});
            tmp[6].push_back({-y, -x});
            tmp[7].push_back({y, x});
        }
        
        for (int i = 0; i < tmp.size(); ++i) {
            sort(tmp[i].begin(), tmp[i].end());
        }
        
        for (int i = 0; i < tmp.size(); ++i) {
            for (int j = 1; j < solutionIn.size(); ++j) {
                tmp[i][j] = {tmp[i][j].first - tmp[i][0].first, tmp[i][j].second - tmp[i][0].second};
            }
            tmp[i][0] = {0, 0};
        }
        
        sort(tmp.begin(), tmp.end());
        
        return tmp[0];
    }
};
