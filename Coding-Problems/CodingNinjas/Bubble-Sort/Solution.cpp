#include "myHeader.hpp"
/*
Problem Statement
You are given an integer array 'arr' of size 'N'.

You must sort this array using 'Bubble Sort'.

Note:
Change in the input array itself. You don't need to return or print the
elements.

Example:
Input: 'N' = 7
'arr' = {2, 13, 4, 1, 3, 6, 28}

Output:
{1, 2, 3, 4, 6, 13, 28}

Explanation:
After applying bubble sort on the input array, the output is {1, 2, 3, 4, 6, 13,
28}

Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying bubble sort on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying bubble sort on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^9
Time Limit: 1 sec
 */

std::pair<bool, size_t> isSorted(std::vector<int> &nums) {
    std::pair<bool, size_t> result(true, nums.size());
    for (size_t i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            result.first = false;
            result.second = i;
            break;
        }
    }
    return result;
}
void bubbleSort(std::vector<int> &arr, size_t n) {
    // write your code here
    std::pair<bool, size_t> sorted = isSorted(arr);
    if (sorted.first) {
        return;
    }
    for (size_t i = sorted.second; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, arr.size());
}

int main() {
    int arr[] = {2, 13, 1, 4, 3, 6, 28};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    bubbleSort(nums, nums.size());
    printList1D(nums);
    // int i = 0;
    // while (i < n) {
    //     std::cout << arr[i];
    //     ++i;
    //     if (i < n) {
    //         std::cout << ", ";
    //     }
    // }
    std::cout << std::endl;
    return 0;
}
