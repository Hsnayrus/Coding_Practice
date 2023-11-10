#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
There is one meeting room in a firm. There are N meetings in the form of
(start[i], end[i]) where start[i] is start time of meeting i and end[i] is
finish time of meeting i. What is the maximum number of meetings that can be
accommodated in the meeting room when only one meeting can be held in the
meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the
other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output:
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output:
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function
maxMeetings() that takes two arrays start[] and end[] along with their size N as
input parameters and returns the maximum number of meetings that can be held in
the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105
 */

typedef struct meeting_tag {
    int n;
    int startTime;
    int endTime;
    meeting_tag(int init_n, int init_startTime, int init_endTime) {
        n = init_n;
        startTime = init_startTime;
        endTime = init_endTime;
    }
} meeting_t;

bool comparator(meeting_t first, meeting_t second) {
    if (first.endTime == second.endTime) {
        return first.n < second.n;
    }
    return first.endTime < second.endTime;
}

/*
Create a struct with three elements: n, startTime and endTime
Create a vector of this custom meeting type, call it schedule
Sort this according in ascending order of endTime.
Create a custom comparator for the sortin
Declare a variable with the first endTime of schedult, call it currentEndTime
Declare a variable called result, which stores the final result initialize it to
1.
Run a loop between 1 and schedule.size(), non inclusive, call it i.
If the current meetings start time is > currentEndTime
then increase count, assign currentEndTime as schedule[i].endTime
return the result
*/

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        std::vector<meeting_t> schedule;
        for (int i = 0; i < n; i++) {
            schedule.push_back(meeting_t(i, start[i], end[i]));
        }
        std::sort(schedule.begin(), schedule.end(), comparator);

        int result = 1;
        int currentEndTime = schedule[0].endTime;
        for (int i = 1; i < n; i++) {
            if (schedule[i].startTime > currentEndTime) {
                currentEndTime = schedule[i].endTime;
                result++;
            }
        }
        return result;
    }
};