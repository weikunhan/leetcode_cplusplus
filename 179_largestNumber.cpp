//==============================================================================
// 179. Largest Number
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> number;
        string res;
        
        for (int i = 0; i < nums.size(); ++i) {
            number.push_back(to_string(nums[i]));
        }
        
        sort(begin(number), end(number), helper);

        for (int i = 0; i < number.size(); ++i) {
            res += number[i];
        }
        
        while (res[0] == '0' && res.size() > 1) {
            res.erase(0, 1);
        }
        
        return  res;
    }
    
private:
    static bool helper(string &a, string &b) {
        return a + b > b + a;
    }
};
