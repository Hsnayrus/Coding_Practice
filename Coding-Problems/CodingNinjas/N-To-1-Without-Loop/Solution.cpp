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
You are given an integer 'n'.

Your task is to return an array containing integers from 'n' to '1'(in
decreasing order) without using loops.

Note:
In the output, you will see the array returned by you.

Example:
Input: 'n' = 5
Output: 5 4 3 2 1
Explanation:
An array containing integers from 'n' to '1' is [5, 4, 3, 2, 1]

Sample Input 1:
5
Sample Output 1 :
5 4 3 2 1
Explanation Of Sample Input 1:
Input: ‘n’ = 5

Output: 5 4 3 2 1

Explanation: An array containing integers from ‘5’ to ‘1’ is [5, 4, 3, 2, 1].
Sample Input 2:
2
Sample Output 2:
2 1
Explanation Of Sample Input 2:
Input: ‘n’ = 2

Output: 2 1

Explanation: An array containing integers from ‘2’ to ‘1’ is [2, 1].
Expected Time Complexity:
The expected time complexity is O(n), where 'n' is the given integer.
Expected Space Complexity:
The expected space complexity is O(n), where 'n' is the given integer.
Constraints:
1 <= n <= 10^4

Time Limit: 1-sec

 */
template <typename T> void printList(std::vector<T> myVector) {
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
void printNosWorker(int i, int n, std::vector<int>& result) {
    if (i == 0) {
        return;
    }
    result.push_back(i);
    printNosWorker(i - 1, n, result);
}
std::vector<int> printNos(int x) {
    // Write your code here
    std::vector<int> result;
    printNosWorker(x, x, result);
    return result;
}

int main() {
    int input;
    std::cin >> input;
    printList(printNos(input));
    return 0;
}