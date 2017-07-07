//==============================================================================
// 55. Jump Game
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/jump-game/#/solutions

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;
        int reachable = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > reachable) {
                return res;
            }
            reachable = max(reachable, i + nums[i]);
        }
        
        return res = true;
    }
};
