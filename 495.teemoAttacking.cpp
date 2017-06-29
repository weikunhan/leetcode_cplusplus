//==============================================================================
// 495. Teemo Attacking
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/teemo-attacking/#/description

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int wakeTime = 0;
        //if (timeSeries.empty()) return 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] < wakeTime) 
                res = res + (timeSeries[i] + duration - wakeTime);
            else 
	        res += duration;
	    wakeTime = timeSeries[i] + duration;
        }
        return res;
    }
};
