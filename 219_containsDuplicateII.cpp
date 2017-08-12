//==============================================================================
// 219. Contains Duplicate II
// C++
// Tag: Array(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> tables;
        bool res = false;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (tables.find(nums[i]) == tables.end()) {
                tables[nums[i]] = i;
            } else { 
                if (i - tables[nums[i]] <= k) {
                    return res = true;
                }
                tables[nums[i]] = i;
            }
        }
        
        return res;
    }
};
