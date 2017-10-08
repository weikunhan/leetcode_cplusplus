//==============================================================================
// 396. Rotate Function
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int firstRound = 0;
        int res = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            firstRound += i * A[i];
            sum += A[i];
        }
        
        res = firstRound;
        
        for (int i = A.size() - 1; i >= 1; --i) {
            firstRound += sum - A.size() * A[i];
            res = max(firstRound, res);
        }
        
        return res;   
    }
};
