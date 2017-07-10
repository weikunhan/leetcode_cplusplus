//==============================================================================
// 53. Maximum Subarray
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/insert-interval/#/descrip

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            res.push_back(intervals[i++]);
        }
        
        newInterval.start = i == intervals.size() ? newInterval.start:min(newInterval.start, intervals[i].start);
        
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            i++;
        }
        
        newInterval.end = i == 0 ? newInterval.end:max(intervals[i - 1].end, newInterval.end);
        res.push_back(newInterval);
        
        while (i < intervals.size()) {
            res.push_back(intervals[i++]);
        }
        
        return res;
    }
};
