//==============================================================================
// 218. The Skyline Problem
// C++
// Tag: Array(Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/the-skyline-problem/description/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>> tables;
        int index = 0;
        
        while (index < buildings.size() || !tables.empty()) {
            int currentX = 0;
            int currentHigh = 0;
            if (tables.empty() || (index < buildings.size() && buildings[index][0] <= tables.top().second)) {
                currentX = buildings[index][0];
                while (index < buildings.size() && buildings[index][0] == currentX) {
                    tables.push(make_pair(buildings[index][2], buildings[index][1]));
                    ++index;
                }
            } else {
                currentX = tables.top().second;
                while (!tables.empty() && tables.top().second <= currentX) {
                    tables.pop();
                }
            }
            currentHigh = (tables.empty()) ? 0:tables.top().first;
            if (res.empty() || res.back().second != currentHigh) {
                res.push_back(make_pair(currentX, currentHigh));
            }
        }
        
        return res;
    }
};
