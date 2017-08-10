//==============================================================================
// 215. Kth Largest Element in an Array
// C++
// Tag: Array(Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> tables(nums.begin(), nums.end());
        int res = 0;
        
        for (int i = 0; i < k - 1; ++i) {
            tables.pop(); 
        }
        
        return res = tables.top();
    }
};
