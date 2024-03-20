#include "myHeader.hpp"
/*
Given an array of meeting time intervals intervals where intervals[i] = [starti,
endi], return the minimum number of conference rooms required.



Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
Example 3:
Input: intervals = [[0,30],[5,10], [5, 50], [6, 30], [8, 28],[15,20]]
Output: 5

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
 */
using std::vector;
class Solution {
    void findMeetingSlot(vector<int>& endTimes, vector<int>& currentMeeting);

  public:
    int minMeetingRooms(vector<vector<int> >& intervals);
};

void Solution::findMeetingSlot(vector<int>& endTimes,
                               vector<int>& currentMeeting) {
    bool newMeeting = true;
    for (size_t i = 0; i < endTimes.size(); i++) {
        // currentMeeting[0] is the start time, currentMeeting[1] is the end
        // time
        if (endTimes[i] <= currentMeeting[0]) {
            endTimes[i] = currentMeeting[1];
            newMeeting = false;
        }
    }
    if (newMeeting) {
        endTimes.push_back(currentMeeting[1]);
    }
}

bool intervalComparator(vector<int>& left, vector<int>& right) {
    return left[0] <= right[0];
}

int Solution::minMeetingRooms(vector<vector<int> >& intervals) {
    vector<int> endTimes;
    std::sort(intervals.begin(), intervals.end(), intervalComparator);
    for (vector<vector<int> >::iterator meetingIt = intervals.begin();
         meetingIt != intervals.end(); ++meetingIt) {
        findMeetingSlot(endTimes, *meetingIt);
    }
    return endTimes.size();
}
/**
 * Algo Mk1:
 * Sort the intervals array based on their start times
 * Create another array called endTimes
 * Iterate through the array intervals
 * Find a Slot for the i^(th) meeting
 * Return the size of the endTimes array
 *
 *
 * Find a Slot for Meeting:
 * takes a reference to the endTimes array
 * another argument is the current meeting
 * Iterate through the endTimes array
 * If the i^(th) endTime is less than the current meetings start Time, then
 * replace that endtime with the current meeting's end Time
 * Else add another entry to the endTimes array with the current endTime
 *
 */