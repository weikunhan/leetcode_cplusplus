//==============================================================================
// 69. Sqrt(x)
// C++
// Tag: Math(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/add-binary/#/description

class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int low = 1;
        int high = INT_MAX;
        
        if (x == 0) {
            return res;
        }
        
        while (true) {
            int mid = low + (high - low) / 2;
            if (mid > x / mid) {
                high = mid - 1;
            } else if (mid + 1 >  x / (mid + 1)) {
                return res = mid;
            } else {
                low = mid +1;    
            }
        }
    }
};
