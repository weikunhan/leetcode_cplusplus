//==============================================================================
// 56. Merge Intervals
// C++
// Tag: Array
//==============================================================================
// Summary:
// https://leetcode.com/problems/merge-intervals/#/description

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), helper);
        
        if (intervals.empty()) {
            return res = {};
        } else {
            res.push_back(intervals[0]);
        }
    
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        
        return res; 
    }
    
private: 
    static bool helper(Interval a, Interval b) {
        return a.start < b.start;
    } 
};
