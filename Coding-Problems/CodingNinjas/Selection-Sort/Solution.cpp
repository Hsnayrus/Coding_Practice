#include "myHeader.hpp"
/*
Problem Statement
Sort the given unsorted array 'arr' of size 'N' in non-decreasing order using
the selection sort algorithm.

Note:
Change in the input/array itself

Example:
Input:
N = 4
arr = {8, 6, 2, 5, 1}

Output:
1 2 5 6 8

Explanation
Switch 8 with 1
1 6 2 5 8
Switch 6 with 2
1 2 6 5 8
Switch 5 with 6
1 2 5 6 8


Sample Input 1:
6
2 13 4 1 3 6
Sample Output 1:
1 2 3 4 6 13
Explanation Of Sample Input 1:
 Select 1 and swap with element at index 0. arr= {1,13,4,2,3,6}

 Select 2 and swap with element at index 1. arr= {1,2,4,13,3,6}

 Select 3 and swap with element at index 2. arr= {1,2,3,13,4,6}

 Select 4 and swap with element at index 3. arr= {1,2,3,4,13,6}

 Select 6 and swap with element at index 4. arr= {1,2,3,4,6,13}
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec
 */
/**
 * Find the element that is wrong in array, that is the point where an element
 * is less than the current element. If no such point exists then this position
 * is 1.
 * Swap it with the smallest element in the array after this element
 * Repeat for all the other elements
 *
 */
std::pair<size_t, size_t> findSmallest(std::vector<int>& vec,
                                       size_t currentIndex) {
    size_t smallestIndex = currentIndex;
    for (size_t i = currentIndex + 1; i < vec.size(); i++) {
        if (vec[i] < vec[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return std::make_pair(currentIndex, smallestIndex);
}

void selectionSort(std::vector<int>& arr) {
    // Write your code here.
    for (size_t i = 0; i < arr.size() - 1; i++) {
        std::pair<size_t, size_t> swapper = findSmallest(arr, i);
        std::swap(arr[swapper.first], arr[swapper.second]);
    }
}
int main() {
    int arr[] = {1, 5, 4, 2, 6, 5, 5, 1, 1};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    selectionSort(nums);
    printList1D(nums);
    return 0;
}
