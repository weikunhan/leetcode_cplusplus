//==============================================================================
// 165. Compare Version Numbers
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/compare-version-numbers/description/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int res = 0;
        int index1 = 0;
        int index2 = 0;
        
        while (index1 < version1.size() || index2 < version2.size()) {
            int number1 = helper(version1, version1.size(), index1);
            int number2 = helper(version2, version2.size(), index2);
            if (number1 > number2) {
                return res = 1;
            }
            if (number1 < number2) {
                return res = -1;
            }
        }
        
        return res;
    }
    
private:
    int helper(string wordIn, int endIn, int &index) {
        int tmp = 0;
        
        while (wordIn[index] != '.' && index < endIn) {
            tmp = tmp * 10 + (wordIn[index] - '0');
            ++index;
        }
        
        ++index;
        
        return tmp;
    }
};
