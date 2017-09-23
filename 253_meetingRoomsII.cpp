//==============================================================================
// 253. Meeting Rooms II
// C++
// Tag: Array(Heap)
//==============================================================================
// Summary:
// https://leetcode.com/problems/meeting-rooms-ii/description/

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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, helper2> tables;
        int res = 0;
        
        if (intervals.empty()) {
            return res;
        }
        
        sort(intervals.begin(), intervals.end(), helper1);
        tables.push(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            Interval tmp = tables.top();
            tables.pop();
            if (intervals[i].start >= tmp.end) {
                tmp.end = intervals[i].end;
            } else {
                tables.push(intervals[i]);
            }
            tables.push(tmp);
        }
        
        return res = tables.size();
    }
    
private:
    static bool helper1(Interval &a, Interval &b) {
        return a.start < b.start;
    }
    
    struct helper2 {
        bool operator() (Interval &a, Interval &b) {
            return a.end >= b.end;
        }
    };
};
