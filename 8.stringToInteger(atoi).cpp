//==============================================================================
// 8. String to Integer (atoi)
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/string-to-integer-atoi/#/description

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0; 
        int i = str.find_first_not_of(' ');
        int sign = 1;
        
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i] == '+' ? sign:-1;
            i++;
        }

//        if (str[i]>=48 && str[i]<=57) {
        if (isdigit(str[i])) {
            for (int j = i; j < str.length(); j++) {
//                if (str[j] >= 48 && str[j] <= 57) {
                if (isdigit(str[j])) {
                    res = res * 10 + (str[j] - 48);
                    if (res > INT_MAX || res < INT_MIN) {
                        res = sign > 0 ? INT_MAX:INT_MIN;
                    }
                } else {
                    break;
                }
            }

        }
        
        res *= sign; 
        return res;
    }
};
