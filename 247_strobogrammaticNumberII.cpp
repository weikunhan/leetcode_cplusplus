//==============================================================================
// 247. Strobogrammatic Number II
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/strobogrammatic-number-ii/description/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        
        return res = helper(n, n);
    }
    
private:
    vector<string> helper(int stepIn, int startIn) {
        vector<string> tmp;
        
        if (stepIn == 0) {
            return tmp = {""};
        }
        
        if (stepIn == 1) {
            return tmp = {"0", "1", "8"};
        }
    
        vector<string> middleList = helper(stepIn - 2, startIn);
    
        for (int i = 0; i < middleList.size(); ++i) {
            string middle = middleList[i];
            if (startIn != stepIn) {
                tmp.push_back("0" + middle + "0");
            }
            tmp.push_back("1" + middle + "1");
            tmp.push_back("8" + middle + "8");
            tmp.push_back("6" + middle + "9");
            tmp.push_back("9" + middle + "6");
        }
        
        return tmp;
    }
};
