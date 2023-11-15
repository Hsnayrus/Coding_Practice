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

Your task is to return an array containing integers from 1 to 'n'(in increasing
order) without using loops.

Example:
Input: 'n' = 5
Output: 1 2 3 4 5
Explanation: An array containing integers from '1' to 'n' is [1, 2, 3, 4, 5]

Sample Input 1:
5
Sample Output 1 :
1 2 3 4 5
Explanation Of Sample Input 1:
The array contains all integers from 1 to 5 in ascending order.
Sample Input 2:
2
Sample Output 2:
1 2
Explanation Of Sample Input 2:
The array contains all integers from 1 to 2 in ascending order.
Expected Time Complexity:
The expected time complexity is O(n), where 'n' is the given integer.
Constraints:
1 <= n <= 10^6

Time Limit: 1-sec

 */
template <typename T> void print(std::vector<T> myVector) {
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
void printNosWorker(int i, int n, std::vector<int>& numbers) {
    if (i > n) {
        return;
    }
    numbers.push_back(i);
    printNosWorker(i + 1, n, numbers);
}

std::vector<int> printNos(int x) {
    // Write your code here
    std::vector<int> result;
    int i = 1;
    printNosWorker(i, x, result);
    return result;
}

int main() {
    int input;
    std::cin >> input;
    std::vector<int> result = printNos(input);
    print(result);
    return 0;
}