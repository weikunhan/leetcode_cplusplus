//==============================================================================
// 17. Letter Combinations of a Phone Number
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        
        if (digits.empty()) {
            return res = {};
        }
        
        for (int i = 0 ; i < digits.length(); i++) {
//            int number = digits[i] - 48;
            int number = digits[i] - '0';
            string candidate = letter[number];
            vector<string> tmp;
            if (number < 0 || number > 9) {
                break;
            }
            if (candidate.empty()) {
                continue;
            }
            for (int j = 0; j < candidate.length(); j++) {
                for (int k = 0; k < res.size(); k++) {
                    tmp.push_back(res[k] + candidate[j]);
                }
            }
            res.swap(tmp);
        } 
        
        return res;
    }
};
