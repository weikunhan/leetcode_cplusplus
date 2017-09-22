//==============================================================================
// 273. Integer to English Words
// C++
// Tag: Math, String
//==============================================================================
// Summary:
// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
public:
    string numberToWords(int num) {
        string res;
        int index = 0;
        
        if (num == 0) {
            return res = "Zero";
        }

        while (num > 0) {
            if (num % 1000 != 0) {
    	        res = helper(num % 1000) + thousands[index] + " " + res;
            }
    	    num /= 1000;
    	    ++index;
        }
    
        return res = res.substr(0, res.find_last_not_of(' ') + 1);
    }

private:
    vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    string helper(int numberIn) {
        if (numberIn == 0) {
            return "";
        } else if (numberIn < 20) {
            return lessThan20[numberIn] + " ";
        } else if (numberIn < 100) {
            return tens[numberIn / 10] + " " + helper(numberIn % 10);
        } else {
            return lessThan20[numberIn / 100] + " Hundred " + helper(numberIn % 100);
        }
    }
};
