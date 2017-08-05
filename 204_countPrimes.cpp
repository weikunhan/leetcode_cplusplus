//==============================================================================
// 204. Count Primes
// C++
// Tag: Math(without Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int res = 0;
        
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++res;
                for (int j = 2; i * j < n; ++j) {
                    prime[i * j] = false;
                }
            }
        }
        
        return res;
    }
};
