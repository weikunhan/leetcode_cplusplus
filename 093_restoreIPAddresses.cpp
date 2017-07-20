//==============================================================================
// 93. Restore IP Addresses
// C++
// Tag: Backtracking
//==============================================================================
// Summary:
// https://leetcode.com/problems/restore-ip-addresses/#/description

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string solution;
        
        helper(s, 0, 0, solution, res); 
        
        return res;
    }
    
private:
    void helper(string ipIn, int startIn, int stepIn, string solutionIn, vector<string> &res) {
        int number = 0;
        
        if (startIn == ipIn.size() && stepIn == 4) {
            solutionIn.erase(solutionIn.end() - 1); 
            res.push_back(solutionIn);
            return;
        }
        
        if (ipIn.size() - startIn > (4 - stepIn) * 3) {
            return;
        }
        
        if (ipIn.size() - startIn < (4 - stepIn)) {
            return;
        }
        
        for (int i = startIn; i < startIn + 3; ++i) {
            number = number * 10 + (ipIn[i] - '0');
            if (number <= 255) {
                solutionIn += ipIn[i];
                helper(ipIn, i + 1, stepIn + 1, solutionIn + '.', res);
            }
            if (number == 0) {
                break;
            }
        }
    }
};
