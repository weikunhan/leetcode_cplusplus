//==============================================================================
// 11. Container With Most Water
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/container-with-most-water/#/description

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() -  1;
        
        while (i < j) {
            int newHeight = min(height[i], height[j]);
            res = max(res, (j - i) * newHeight);
            while (height[i] == newHeight && i < j) {
                i++;
            }
            while (height[j] == newHeight && i < j) {
                j--;
            }
        }
        
        return res;
    }
};
