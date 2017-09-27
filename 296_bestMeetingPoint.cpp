//==============================================================================
// 296. Best Meeting Point
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/best-meeting-point/description/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> yDimension;
        vector<int> xDimension;
        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    xDimension.push_back(j);
                    yDimension.push_back(i);
                }
            }
        }

        sort(xDimension.begin(), xDimension.end());
        sort(yDimension.begin(), yDimension.end());
        int length = xDimension.size();
        int xMedian = xDimension[length / 2];
        int yMedian = yDimension[length / 2];


        for (int i = 0; i < length; ++i) {
            int tmp = abs(xDimension[i] - xMedian) + abs(yDimension[i] - yMedian);
            res += tmp;
        }
        
        return res;
    }
};
