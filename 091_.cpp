class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> res(n+1, 0);
        
        if (s.empty()) {
            return res[0];
        } else {
            res[n] = 1;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') {
                res[i] = res[i + 1];
                if (i < n - 1 && stoi(s.substr(i, 2)) <= 26)
                    res[i] += res[i + 2];
            }
        }
        return res[0];
    
    }
};
