//==============================================================================
// 276. Paint Fence
// C++
// Tag: Array(without DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/paint-fence/description/

class Solution {
public:
    int numWays(int n, int k) {
        int res = 0;
        int diffColorCount = k * (k - 1);
        int sameColorCount = k;
        
        if (n == 0) {
            return res;
        } else if (n == 1) {
            return k;
        }

        for (int i = 2; i < n; ++i) {
            int temp = diffColorCount;
            diffColorCount = (diffColorCount + sameColorCount) * (k - 1);
            sameColorCount = temp;
        }
        
        return res = diffColorCount + sameColorCount;
    }
};
