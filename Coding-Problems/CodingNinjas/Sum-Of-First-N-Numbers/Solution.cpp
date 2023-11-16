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

Your task is determining the sum of the first 'n' natural numbers and returning
it.

Example:
Input: 'n' = 3
Output: 6
Explanation: The sum of the first 3 natural numbers is 1 + 2 + 3, equal to 6


Sample Input 1:
3
Sample Output 1 :
6
Explanation Of Sample Input 1:
Input: ‘n’ = 3

Output: 6

Explanation: The sum of the first 3 natural numbers is 1 + 2 + 3, equal to 6.
Sample Input 2:
5
Sample Output 2:
15
Explanation of sample output 2:
Input: ‘n’ = 5

Output: 15

Explanation: The sum of the first 5 natural numbers is 1 + 2 + 3 + 4 + 5, equal
to 15. Expected Time Complexity: The expected time complexity is O(1). Expected
Space Complexity: The expected space complexity is O(1). Constraints: 1 <= n <=
10^9 Time Limit: 1 sec

 */
long long sumFirstN(long long n) {
    // Write your code here.
    return ((n * (n + 1)) / 2);
}

int main() {
    long long input;
    std::cin >> input;
    std::cout << sumFirstN(input) << std::endl;
    return 0;
}