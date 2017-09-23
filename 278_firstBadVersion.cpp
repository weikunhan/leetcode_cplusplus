//==============================================================================
// 278. First Bad Version
// C++
// Tag: Array(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/first-bad-version/description/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int res = 0;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!isBadVersion(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return res = low;
    }
};
