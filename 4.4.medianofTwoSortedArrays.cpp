//==============================================================================
// 4. Median of Two Sorted Arrays
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/median-of-two-sorted-arrays/#/description

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeArray;
        double res;
        mergeArray.reserve(nums1.size() + nums2.size()); 
		    mergeArray.insert(mergeArray.end(), nums2.begin(), nums2.end() );
		    mergeArray.insert(mergeArray.end(), nums1.begin(), nums1.end() );
        sort(mergeArray.begin(), mergeArray.end());
        int median = mergeArray.size() / 2; 
        
        if (mergeArray.size() % 2 == 0) {
            res = (mergeArray[median - 1] + mergeArray[median]) / 2.0;
        } else {
            res = mergeArray[median];
        }
        
        return res;
    }
};
