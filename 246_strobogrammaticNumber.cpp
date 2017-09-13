//==============================================================================
// 246. Strobogrammatic Number
// C++
// Tag: Math(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/strobogrammatic-number/description/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> tables = {{'0', '0'}, 
                                            {'1', '1'}, 
                                            {'6', '9'}, 
                                            {'8', '8'}, 
                                            {'9', '6'}};
        bool res = false;
        int left = 0;
        int right = num.size() - 1;
        
        while (left <= right) {
            if (tables.find(num[left]) == tables.end() || tables[num[left]] != num[right]) {
                return res; 
            }
            ++left;
            --right;
        }
        
        return res = true; 
    }
};
