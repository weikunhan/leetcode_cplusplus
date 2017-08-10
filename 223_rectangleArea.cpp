//==============================================================================
// 223. Rectangle Area
// C++
// Tag: Math
//==============================================================================
// Summary:
// https://leetcode.com/problems/rectangle-area/description/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = 0; 
        
        int left = max(A, E);
        int right = max(min(C, G), left);
        int bottom = max(B, F); 
        int top = max(min(D, H), bottom);
        int overlap = (right - left) * (top - bottom);
       
        return res = (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};
