//==============================================================================
// 554. Brick Wall
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// For every row, whenever add a brick, it record the end position as +1.
// The goal is to find the position where most row have a break on that position.

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int sameEdge = 0;
        for (auto n : wall) {
            int count = 0;
            for (int i = 0; i < n.size() - 1; i++) {
                count += n[i];
                ++hash[count];
                sameEdge = max(sameEdge, hash[count]);
            }
        }
        return wall.size() - sameEdge;
    }
};
