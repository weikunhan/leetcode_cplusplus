//==============================================================================
// 167. Two Sum II - Input Array is Sorted
// C++
// Tag: Array(2 Pointers, without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0;
        int right = numbers.size() - 1;
        
        while (numbers[left] + numbers[right] != target) {
            if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        
        res.push_back(left + 1);
        res.push_back(right + 1);
        
        return res;
    }
};
