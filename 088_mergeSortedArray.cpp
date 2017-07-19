//==============================================================================
// 88. Merge Sorted Array
// C++
// Tag: Array(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/merge-sorted-array/#/description

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = n - 1;
        int i = m + n - 1;
        
        while (right >= 0) {
            nums1[i--] = (left >= 0 && nums1[left] > nums2[right]) ? nums1[left--]:nums2[right--];
        }
    }
};
