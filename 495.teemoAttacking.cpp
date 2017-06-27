//==============================================================================
// 495. Teemo Attacking
// C++
// Tag: Array
//==============================================================================
// Summary:
// The easy way is to use a hash table with key value are all files contents, 
// and store files name with same key value. Finally, print all the size of mapped 
// value is greate than 1, which prints the duplicates. 
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
