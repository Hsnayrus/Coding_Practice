#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
/*
Problem Statement
Given an array 'arr' of size 'n'.
Return an array with all the elements placed in reverse order.

Note:
You don't need to print anything. Just implement the given function.

Example:
Input: n = 6, arr = [5, 7, 8, 1, 6, 3]
Output: [3, 6, 1, 8, 7, 5]
Explanation:
After reversing the array, it looks like this [3, 6, 1, 8, 7, 5]


Sample Input 1:
8
3 1 1 7 4 2 6 11
Sample Output 1:
11 6 2 4 7 1 1 3
Explanation Of Sample Input 1 :
After reversing the array, it looks like this [11, 6, 2, 4, 7, 1, 1, 3].
Sample Input 2:
4
8 1 3 2
Sample Output 2:
2 3 1 8
Explanation Of Sample Input 2 :
After reversing the array, it looks like this [2, 3, 1, 8].
Expected time complexity
The expected time complexity is O(n).
Constraints:
1 <= 'n' <= 10^6
-10^9 <= 'arr[i]' <=10^9

 */
template <typename T> void printList(std::vector<T>& myVector) {
    typename std::vector<T>::iterator myIterator = myVector.begin();
    while (myIterator != myVector.end()) {
        std::cout << *myIterator;
        ++myIterator;
        if (myIterator != myVector.end()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

std::vector<int> reverseArray(int n, std::vector<int>& nums) {
    // Write your code here
    int i = 0;
    while (i < n / 2) {
        int temp = nums[i];
        nums[i] = nums[nums.size() - i - 1];
        nums[nums.size() - i - 1] = temp;
        ++i;
    }
    return nums;
}
int main() {
    int arr[] = {1, 2, 4, 5, 6, 7, 8};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    printList(nums);
    std::vector<int> result = reverseArray(8, nums);
    printList(result);
    printList(nums);
    return 0;
}