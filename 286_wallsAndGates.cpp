//==============================================================================
// 286. Walls and Gates
// C++
// Tag: Array(without BFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/walls-and-gates/description/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) {
                    helper(i, j, 0, rooms);
                }
            }
        }
    }
    
private:
    void helper(int stepIn1, int stepIn2, int numberIn, vector<vector<int>> &rooms) {
        if (stepIn1 < 0 || stepIn1 >= rooms.size() || stepIn2 < 0 || stepIn2 >= rooms[stepIn1].size() || rooms[stepIn1][stepIn2] < numberIn) {
            return;
        }
        
        rooms[stepIn1][stepIn2] = numberIn;
        helper(stepIn1 + 1, stepIn2, numberIn + 1, rooms);
        helper(stepIn1 - 1, stepIn2, numberIn + 1, rooms);
        helper(stepIn1, stepIn2 + 1, numberIn + 1, rooms);
        helper(stepIn1, stepIn2 - 1, numberIn + 1, rooms);
    }
};
