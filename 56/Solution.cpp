#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals that
cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
 */
class Solution {
  public:
    std::vector<std::vector<int> >
    merge(std::vector<std::vector<int> >& intervals) {
        std::vector<std::vector<int> > result;
        std::sort(intervals.begin(), intervals.end());

        for (size_t i = 0; i < intervals.size(); i++) {
            std::vector<int> current(intervals[i].begin(), intervals[i].end());
            std::cout << "Result Size: " << result.size() << std::endl;
            if (result.size() != 0 && current[0] <= result.back()[1]) {
                continue;
            }
            for (size_t j = 0; j < intervals.size(); j++) {
                if (intervals[j][0] <= current[1]) {
                    if (intervals[j][1] > current[1]) {
                        current[1] = intervals[j][1];
                    }
                } else {
                    break;
                }
            }
            result.push_back(current);
        }
        return result;
    }
};

template <typename T> void printList(const std::vector<T>& list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int> > intervals;
    int first[] = {1, 4};
    int second[] = {2, 6};
    int third[] = {8, 10};
    int fourth[] = {13, 14};
    std::vector<int> firstV(first, (first + sizeof(first) / sizeof(int)));
    std::vector<int> secondV(second, (second + sizeof(second) / sizeof(int)));
    std::vector<int> thirdV(third, third + sizeof(third) / sizeof(int));
    std::vector<int> fourthV(fourth, fourth + sizeof(fourth) / sizeof(int));
    intervals.push_back(firstV);
    intervals.push_back(secondV);
    intervals.push_back(thirdV);
    intervals.push_back(fourthV);
    for (size_t i = 0; i < intervals.size(); i++) {
        printList(intervals[i]);
    }
    std::cout << "Chala daalaa\n";
    std::sort(intervals.begin(), intervals.end());
    Solution s1;
    std::vector<std::vector<int> > result = s1.merge(intervals);
    for (size_t i = 0; i < intervals.size(); i++) {
        printList(result[i]);
    }
    return EXIT_SUCCESS;
}
