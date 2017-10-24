//==============================================================================
// 711. Number of Distinct Islands II
// C++
// Tag: Array(Hash Table, DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/number-of-distinct-islands-ii/description/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
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
        if (stepIn1 < 0 || stepIn2 < 0 || stepIn1 >= grid.size() || stepIn2 >= grid[0].size()) {
            return;
        }
        
        if (grid[stepIn1][stepIn2] != 1) {
            return;
        }
        
        grid[stepIn1][stepIn2] = 0;
        tables[numberIn].push_back({stepIn1, stepIn2});
        helper1(stepIn1 + 1, stepIn2, numberIn, grid);
        helper1(stepIn1, stepIn2 + 1, numberIn, grid);
        helper1(stepIn1 - 1, stepIn2, numberIn, grid);
        helper1(stepIn1, stepIn2 - 1, numberIn, grid);
    }
    
    vector<pair<int,int>> helper2(vector<pair<int,int>> solutionIn) {
        vector<pair<int,int>> tmp;
        
        for (int i = 0; i < solutionIn.size(); ++i) {
            tmp.push_back({solutionIn[i].first, solutionIn[i].second});
        }
        
        sort(tmp.begin(), tmp.end());
        
        for (int i = 1; i < solutionIn.size(); ++i) {
            tmp[i] = {tmp[i].first - tmp[0].first, tmp[i].second - tmp[0].second};
        }
        
        tmp[0] = {0, 0};
        
        return tmp;
    }
};
