//==============================================================================
// 241. Different Ways to Add Parentheses
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/different-ways-to-add-parentheses/description/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;

        for (int i = 0; i < input.size(); ++i) {
            char tmp = input[i];
            if (tmp == '+' || tmp == '-' || tmp == '*') {
                vector<int> part1 = diffWaysToCompute(input.substr(0, i));
                vector<int> part2 = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < part1.size(); ++j) {
                    for (int k = 0; k < part2.size(); ++k) {
                        if (tmp == '+') {
                            res.push_back(part1[j] + part2[k]);
                        } else if (tmp == '-') {
                            res.push_back(part1[j] - part2[k]);
                        } else {
                            res.push_back(part1[j] * part2[k]);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        
        return res;
    }
};
