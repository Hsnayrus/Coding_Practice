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

Your task is to return a sorted array(in increasing order) containing all the
factorial numbers which are less than or equal to 'n'.

The factorial number is a factorial of a positive integer, like 24 is a
factorial number, as it is a factorial of 4.

Note:
In the output, you will see the array returned by you

Example:
Input: 'n' = 7
Output: 1 2 6
Explanation: Factorial numbers less than or equal to '7' are '1', '2' and '6'.


Sample Input 1:
7
Sample Output 1 :
1 2 6
Explanation Of Sample Input 1:
Input: ‘n’ = 7

Output: 1 2 6

Explanation: Factorial numbers less than or equal to ‘7’ are ‘1’, ‘2’, and ‘6’.
Sample Input 2:
2
Sample Output 2:
1 2
Explanation Of Sample Input 2:
Input: ‘n’ = 2

Output: 1 2

Explanation: Factorial numbers less than or equal to ‘2’ are ‘1’ and ‘2’.
Expected Time Complexity:
The expected time complexity is O(m), where ‘m’ is the number of factorial
numbers which are less than or equal to ‘n’. Expected Space Complexity: The
expected space complexity is O(m), where ‘m’ is the number of factorial numbers
which are less than or equal to ‘n’. Constraints: 1 <= n <= 10^18

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

void factorialNumbersWorker(long long i, long long n,
                            std::vector<long long>& result) {
    if (i > n) {
        return;
    }
    result.push_back(i);
    factorialNumbersWorker((i * (result.size() + 1)), n, result);
}

std::vector<long long> factorialNumbers(long long n) {
    // Write your code here
    std::vector<long long> result;
    int i = 1;
    factorialNumbersWorker(i, n, result);
    return result;
}
int main() {
    long long input;
    std::cin >> input;
    printList(factorialNumbers(input));
    return 0;
}