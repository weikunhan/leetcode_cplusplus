class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
		int len = s1.length();
		vector<vector<vector<bool>>> F(len, vector<vector<bool> >(len, vector<bool>(len + 1)));
		for (int k = 1; k <= len; ++k) {
			for (int i = 0; i + k <= len; ++i) {
				for (int j = 0; j + k <= len; ++j) {
					if (k == 1)
						F[i][j][k] = s1[i] == s2[j];
					else 
                        for (int q = 1; q < k && !F[i][j][k]; ++q) {
					F[i][j][k] = (F[i][j][q] && F[i + q][j + q][k - q]) || (F[i][j + k - q][q] && F[i + q][j][k - q]);
					}
                }
            }
        }
		
        return F[0][0][len];
    }
};
