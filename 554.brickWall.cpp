//==============================================================================
// 554. Brick Wall
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// For every row, whenever add a brick, it record the end position as +1.
// The goal is to find the position where most row have a break on that position.
// https://leetcode.com/problems/brick-wall/#/description

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> bricks;
        int sameEdge = 0;
        
        for (auto brick:wall) {
            int count = 0;
            for (int i = 0; i < brick.size() - 1; i++) {
                count += brick[i];
                ++bricks[count];
                sameEdge = max(sameEdge, bricks[count]);
            }
        }
        
        return wall.size() - sameEdge;
    }
};
