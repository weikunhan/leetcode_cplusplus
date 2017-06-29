//==============================================================================
// 1. Tow Sum
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// https://leetcode.com/problems/two-sum/#/description

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (numbers.find(difference) != numbers.end()) {
                res.push_back(numbers[difference]);
                res.push_back(i);
            }
            numbers[nums[i]] = i;
        }
        
        return res;
    }
};
