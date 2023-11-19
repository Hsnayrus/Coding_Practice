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
You are given an array 'arr' of length 'n' containing integers within the range
'1' to 'x'.

Your task is to count the frequency of all elements from 1 to n.

Note:
You do not need to print anything. Return a frequency array as an array in the
function such that index 0 represents the frequency of 1, index 1 represents the
frequency of 2, and so on.

Example:
Input: 'n' = 6, 'x' = 9, 'arr' = {1, 3, 1, 9, 2, 7}
Output:[2, 1, 1, 0, 0, 0]
Explanation: Below Table shows the number and their counts, respectively  in the
array

Number  Count
1		2
2		1
3		1
4		0
5		0
6		0

Sample Input 1:
6 4
1 3 4 3 4 1
Sample Output 1:
2 0 2 2 0 0
Explanation Of Sample Input 1 :
Frequency table:
Number         Count
 1                2
 2                0
 3                2
 4                2
 5                0
 6                0
Sample Input 2 :
5 5
1 2 3 4 5
Sample Output 2 :
1 1 1 1 1
Explanation Of Sample Input 2 :
Frequency table:
Number         Count
 1                1
 2                1
 3                1
 4                1
 5                1
Constraints:
1  <= n <= 10^5
1  <= x <= 10^5
1 <= arr[i] <= x
 */
template <typename T> void printList(std::vector<T> & myVector) {
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

std::vector<int> countFrequency(int n, int x, std::vector<int> & nums) {
    // Write your code here.
    std::vector<int> result(n, 0);
    for (size_t i = 0; i < n; i++) {
        if (nums[i] <= n) {
            result[nums[i] - 1]++;
        }
    }
    return result;
}

int findMaxElement(std::vector<int> & nums) {
    int max = nums[0];
    for (size_t i = 1; i <= nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {1, 3, 4, 3, 4, 1};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    std::vector<int> result =
        countFrequency(int(nums.size()), findMaxElement(nums), nums);
    printList(result);
    return 0;
}
