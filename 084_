//==============================================================================
// 84. Largest Rectangle in Histogram
// C++
// Tag: Stack
//==============================================================================
// Summary:
// https://leetcode.com/problems/largest-rectangle-in-histogram/#/description

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> levels;
        int res = 0;
        heights.push_back(0);
            
        for (int i = 0; i < heights.size(); ++i) {
            while (!levels.empty() && heights[levels.top()] >= heights[i]) {
                int top = heights[levels.top()];
                levels.pop();
                int index = (!levels.empty()) ? levels.top():-1;
                int distance = i - index - 1;
                res = max(res, top * distance);
            }
            levels.push(i);
        }
            
        heights.pop_back();
        
        return res;
    }
};
