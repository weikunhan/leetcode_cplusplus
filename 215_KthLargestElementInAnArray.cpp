//==============================================================================
// 215. Kth Largest Element in an Array
// C++
// Tag: Array(without Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> tables;
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) { 
            tables.insert(nums[i]);
            if (tables.size() > k) {
                tables.erase(tables.begin());
            }
        }
        
        return res = *tables.begin();
    }
};
