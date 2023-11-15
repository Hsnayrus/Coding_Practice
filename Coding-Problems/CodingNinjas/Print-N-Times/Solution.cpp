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

Return an array having "Coding Ninjas", 'n' times, without using a loop.

Example:
Input: 'n' = 4

Output:
Coding Ninjas Coding Ninjas Coding Ninjas Coding Ninjas

Explanation: "Coding Ninjas" is printed 4 times.


Sample Input 1:
3


Sample Output 1:
Coding Ninjas Coding Ninjas Coding Ninjas


Explanation of sample output 1:
“Coding Ninjas” is printed 3 times.

Sample Input 2:
5


Sample Output 2:
Coding Ninjas Coding Ninjas Coding Ninjas Coding Ninjas Coding Ninjas


Expected Time Complexity:
Try to solve this in O(n).


Expected Space Complexity:
Try to solve this in O(n).


Constraints:
1 <= 'n' <= 10^4

Time Limit: 1 sec

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
void printNTimesWorker(int i, int n, std::vector<std::string>& result) {
    if (i == n) {
        return;
    }
    result.push_back("Coding Ninjas");
    printNTimesWorker(i + 1, n, result);
}
std::vector<std::string> printNTimes(int n) {
    // Write your code here
    int i = 0;
    std::vector<std::string> result;
    printNTimesWorker(i, n, result);
    return result;
}
int main() {
    int input;
    std::cin >> input;
    std::vector<std::string> result = printNTimes(input);
    print(result);
    return 0;
}