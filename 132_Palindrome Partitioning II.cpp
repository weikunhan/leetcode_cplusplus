class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> res(n + 1);  
        
        for (int i = 0; i <= n; ++i) {
            res[i] = i - 1;
        }
        
        for (int i = 0; i < n; ++i) {
            int left = 0;
            while (left <= i && i + left < n && s[i - left] == s[i + left]) {
                res[i + left + 1] = min(res[i + left + 1], res[i - left] + 1);
                ++left;

            }
            left = 1;
            while (left <= i + 1 && i + left< n && s[i - left + 1] == s[i + left]) {
                res[i + left + 1] = min(res[i + left +1 ], res[i - left +1] + 1 );
                ++left;

            }
        }
                    
        return (res[n] > 0) ? res[n]:0;
    }
};
