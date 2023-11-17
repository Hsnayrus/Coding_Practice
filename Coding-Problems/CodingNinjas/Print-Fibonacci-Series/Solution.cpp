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
Given an integer 'n', return first n Fibonacci numbers using a generator
function.

Example:
Input: 'n' = 5
Output: 0 1 1 2 3
Explanation: First 5 Fibonacci numbers are 0, 1, 1, 2 and 3

Note:
You don't need to print anything, just implement the given function.

Sample Input 1:
5
Sample Output 1:
0 1 1 2 3
Explanation Of Sample Input 1:
The first 5 Fibonacci numbers are 0, 1, 1, 2, and 3.
Sample Input 2:
3
Sample Output 2:
0 1 1
Explanation Of Sample Input 2:
The first 5 Fibonacci numbers are 0, 1, 1.
Expected time complexity
The expected time complexity is O(n).
Constraints:
1 <= n <= 45
Time Limit: 1 s

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

std::vector<int> generateFibonacciNumbers(int n) {
    // Write your code here
    std::vector<int> sequence;
    sequence.push_back(0);
    if (n == 1) {
        return sequence;
    }
    sequence.push_back(1);
    for (int i = 2; i < n; i++) {
        sequence.push_back(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}
int main() {
    int input;
    std::cin >> input;
    std::vector<int> result = generateFibonacciNumbers(input);
    printList(result);
    return 0;
}