//==============================================================================
// 240. Search a 2D Matrix II
// C++
// Tag: Array(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int low = 0;
        int high = 0;    

        if (matrix.empty()) {
            return res;
        } else {
            high = matrix[0].size() - 1;
        }
    
        while (low < matrix.size() && high >= 0) {
            if (matrix[low][high] == target) {
                return res = true;
            } else if (matrix[low][high] > target) {
                --high;
            } else {
                ++low;
            }
        }
        
        return res;
    }
};
