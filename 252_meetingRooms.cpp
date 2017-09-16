//==============================================================================
// 252. Meeting Rooms
// C++
// Tag: Design
//==============================================================================
// Summary:
// https://leetcode.com/problems/meeting-rooms/description/

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool res = false;
        
        if (intervals.empty()) {
            return res = true;
        }
        
        sort(intervals.begin(), intervals.end(), helper);

        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end > intervals[i + 1].start) {
                return res;
            }
        }

        return res = true;
    }
    
private:
    static bool helper(Interval &a, Interval &b) {
        return a.start < b.start;
    }
};
