//==============================================================================
// 166. Fraction to Recurring Decimal
// C++
// Tag: Math(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long number1 = numerator;
        long long number2 = denominator;
        string res;
        
        string sign = (number1 * number2 < 0) ? "-":"";
        number1 = abs(number1);
        number2 = abs(number2);
        long long remainder = number1 % number2;
        res = sign + to_string(number1 / number2);
          
        return (remainder == 0) ? res:(res + "." + helper(remainder, number2));
    }
      
private:
    string helper(long long remainderIn, long long numberIn) {
        unordered_map<int, int> tables;
        int index = 0;
        string tmp;
        
        while (remainderIn != 0 && tables.find(remainderIn) == tables.end()) {
            tables[remainderIn] = index;
            ++index;
            remainderIn *= 10;
            tmp.append(to_string(remainderIn / numberIn));
            remainderIn %= numberIn;
        }
          
        if (remainderIn != 0) {
            tmp.insert(tables[remainderIn], "(");
            tmp.append(")");
        }
        
        return tmp;  
    }
};
