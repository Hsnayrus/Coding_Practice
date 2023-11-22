#include "myHeader.hpp"
/*
Problem Statement
You are given an integer 'arr' of size 'N'.
You must sort this array using 'Insertion sort' recursively.

Note:
Change in the input array itself. You don't need to return or print the elements

Example:
Input: 'N' = 7
'arr' = {2, 13, 4, 1, 3, 6, 28}

Output:
{1, 2, 3, 4, 6, 13, 28}

Explanation:
After appying insertion sort on the input array, the output is {1, 2, 3, 4, 6,
13, 28}




Sample Input 1:>
5
9 3 6 2 0
Sample Output 1:>
0 2 3 6 9
Sample Input 2:>
4
4 3 2 1
Sample Output 2:>
1 2 3 4
Constraints :>
0 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec
 */
void findRightPlace(int arr[], int n, int startIndex) {
    for (int j = startIndex; j > 0; j--) {
        if (arr[j - 1] > arr[j]) {
            std::swap(arr[j - 1], arr[j]);
        }
    }
}
void insertionSort(int arr[], int n) {
    // write your code here
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            findRightPlace(arr, n, i);
        }
    }
}
int main() {
    int arr[] = {2, 13, 3, 4, 1, 5, 6, 3};
    int n = 8;
    insertionSort(arr, n);
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    printList1D(nums);
    return 0;
}
