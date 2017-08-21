//==============================================================================
// 167. Two Sum II - Input Array is Sorted
// C++
// Tag: Array(Binary Search, without 2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int low = 0;
        int high = numbers.size() - 1;
        
        while (numbers[low] + numbers[high] != target) {
            if (numbers[low] + numbers[high] < target) {
                ++low;
            } else {
                --high;
            }
        }
        
        res.push_back(low + 1);
        res.push_back(high + 1);
        
        return res;
    }
};
