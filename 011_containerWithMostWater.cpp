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
        int left = 0;
        int right = height.size() -  1;
        
        while (left < right) {
            int newHeight = min(height[left], height[right]);
            res = max(res, (right - left) * newHeight);
            while (height[left] == newHeight && left < right) {
                left++;
            }
            while (height[right] == newHeight && left < right) {
                right--;
            }
        }
        
        return res;
    }
};
