#include "myHeader.hpp"
/*
Problem statement
You are given an integer array 'arr' of size 'N'.
You must sort this array using 'Bubble Sort'.

Note:
Change in the input array itself. You don't need to print or return the
elements.

Example:
Input: 'N' = 7
'arr' = {2, 13, 4, 1, 3, 6, 28}

Output: {1, 2, 3, 4, 6, 14, 28}

Explanation: After applying bubble sort on the input array, the output is {1, 2,
3, 4, 6, 13, 28}

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
/**
 * Iterate through the array until the second last element(< n - 1)
 * If the current element is greater than the next element
 *     Iterate the array from the current element to the first one.
 * 	   For every element greater than swap the current element with the
 * previous element Else just move through the array
 */
void bubbleSort(std::vector<int> & nums, int n) {
    if (n == nums.size()) {
        n = 1;
    }
    if (nums[n] < nums[n - 1]) {
        size_t j = n;
        while (j > 0 && nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    if (n == nums.size() - 1 || n > nums.size()) {
        return;
    }
    bubbleSort(nums, n + 1);
}
int main() {
    int arr[] = {4, 31, 22, 23, 2, 32, 1, 3, 4, 55, 99};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    printList1D(nums);
    std::cout << "After sorting\n";
    bubbleSort(nums, int(nums.size()));
    printList1D(nums);
    return 0;
}
