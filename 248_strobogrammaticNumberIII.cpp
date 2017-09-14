//==============================================================================
// 247. Strobogrammatic Number III
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/strobogrammatic-number-iii/description/

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        vector<string> solution;

        for (int i = low.size(); i <= high.size(); ++i) {
            vector<string> tmp = helper(i, i);
            solution.insert(solution.end(), tmp.begin(), tmp.end());
        }

		for (int i = 0; i < solution.size(); ++i) {
            if ((solution[i].size() == low.size() && solution[i].compare(low) < 0 ) || 
                (solution[i].size() == high.size() && solution[i].compare(high) > 0)) {
			    continue;
            }
            ++res;
        }
        
		return res;
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
