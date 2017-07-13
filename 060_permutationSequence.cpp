//==============================================================================
// 60. Permutation Sequence
// C++
// Tag: Backtracking(DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/permutation-sequence/#/description

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> number;
        vector<int> factorial(n + 1, 1);
        string res;
        int sum = 1;
        
        for (int i = 1; i <= n; ++i) {
            sum *= i;
            factorial[i] = sum;
        }

        for(int i = 1; i <= n; ++i) {
            number.push_back(to_string(i));
        }

        --k;
    
        for(int i = 1; i <= n; ++i){
            int index = k / factorial[n - i];
            res += number[index];
            number.erase(number.begin() + index);
            k -= index * factorial[n - i];
        }
    
        return res; 
    }
};
