//==============================================================================
// 229. Majority Element II
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/majority-element-ii/description/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int target1 = 0;
        int target2 = 0;
        int number1 = 0;
        int number2 = 0;
        int total1 = 0;
        int total2 = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (number1 != 0 && target1 == nums[i]) {
                ++number1;
                continue;
            } 
            if (number2 != 0 && target2 == nums[i]) {
                ++number2;
                continue;
            }
            if (number1 == 0) { 
                target1 = nums[i];
                ++number1;
                continue;
            }
            if (number2 == 0) {
                target2 = nums[i];
                ++number2;
                continue;
            }
            --number1;
            --number2;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (number1 > 0) { 
                if (nums[i] == target1) { 
                    ++total1;
                }
            }
            if (number2 > 0) {
                if (nums[i] == target2) { 
                    ++total2;
                }
            }
        }
        
        if (total1 > nums.size() / 3) {
            res.push_back(target1);
        }
        
        if (total2 > nums.size() / 3) {
            res.push_back(target2);
        }
        
        return res;  
    }
};
