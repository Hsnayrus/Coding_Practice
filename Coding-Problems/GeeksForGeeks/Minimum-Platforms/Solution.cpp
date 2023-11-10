#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given arrival and departure times of all trains that reach a railway station.
Find the minimum number of platforms required for the railway station so that no
train is kept waiting. Consider that all the trains arrive on the same day and
leave on the same day. Arrival and departure time can never be the same for a
train but we can have arrival time of one train equal to departure time of the
other. At any given instance of time, same platform can not be used for both
departure of a train and arrival of another train. In such cases, we need
different platforms.

Example 1:

Input: n = 6
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation:
Minimum 3 platforms are required to safely arrive and depart all trains.


Example 2:
Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation:
Only 1 platform is required to safely manage the arrival and departure of all
trains.

Your Task:
YOu don't need to read input or print anything. Your task is to complete the
function findPlatform() which takes the array arr[](denoting the arrival times),
array dep[](denoting the departure times) and the size of the array as inputs
and returns the minimum number of platforms required at the railway station such
that no train waits.

Note: Time intervals are in the 24-hour format(HHMM), where the first two
characters represent hour(between 00 to 23) and the last two characters
represent minutes(this may be > 59).

Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 50000
0000 <= A[i] <= D[i] <= 2359
 */

typedef struct Schedule_Type {
    int startTime;
    int endTime;
    int n;

    Schedule_Type(int init_startTime, int init_endTime, int init_n) {
        startTime = init_startTime;
        endTime = init_endTime;
        n = init_n;
    }
} schedule_t;

bool comparator(schedule_t first, schedule_t second) {
    if (first.endTime < second.endTime) {
        return true;
    } else if (first.endTime == second.endTime) {
        return first.n < second.n;
    } else {
        return false;
    }
}
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Your code here
        std::vector<schedule_t> newSchedule;
        for (int i = 0; i < n; i++) {
            schedule_t temp(arr[i], dep[i], i);
            newSchedule.push_back(temp);
        }
        std::sort(newSchedule.begin(), newSchedule.end(), comparator);
        std::vector<schedule_t>::iterator currentTiming = newSchedule.begin();
        ++currentTiming;

        int count = 1;

        std::vector<int> limits;
        limits.push_back(newSchedule[0].endTime);
        while (currentTiming != newSchedule.end()) {
            bool found = false;
            for (int i = 0; i < limits.size(); i++) {
                if ((*currentTiming).startTime > limits[i]) {
                    found = true;
                    limits[i] = (*currentTiming).endTime;
                    break;
                }
            }
            if (!found) {
                limits.push_back((*currentTiming).endTime);
                count++;
            }
            ++currentTiming;
        }
        return count;
    }
};

int main() {
    int n = 6;
    int arr[6] = {900, 940, 950, 1100, 1500, 1800};
    int dep[6] = {910, 1200, 1120, 1130, 1900, 2000};
    Solution s1;
    std::cout << "Count is: " << s1.findPlatform(arr, dep, n) << std::endl;
}
