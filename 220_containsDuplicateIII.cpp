//==============================================================================
// 220. Contains Duplicate III
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/contains-duplicate-iii/description/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> tables;
        bool res = false;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                tables.erase(nums[i - k - 1]);
            }
            auto it = tables.lower_bound((long long)nums[i] - t);
            if (it != tables.end() && *it - nums[i] <= t) {
                return res = true;
            } 
            tables.insert(nums[i]);
        }
    
        return res;
    }
};
