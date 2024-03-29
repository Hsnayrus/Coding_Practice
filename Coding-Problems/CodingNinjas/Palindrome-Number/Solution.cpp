#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
Check whether a given number 'n' is a palindrome number.

Note:
Palindrome numbers are the numbers that don't change when reversed.
You don't need to print anything. Just implement the given function.

Example:
Input: 'n' = 51415
Output: True
Explanation: On reversing, 51415 gives 51415


Sample Input 1 :
1032
Sample Output 1 :
false
Explanation Of Sample Input 1:
1032, on being reversed, gives 2301, which is a totally different number.
Sample Input 2 :
121
Sample Output 2 :
true
Explanation Of Sample Input 2:
121, on being reversed, gives 121, which is the same.
Expected time complexity:
The expected time complexity is O(log(n)).
Constraints :
1 <= n <= 10^9
Time Limit: 1 sec

 */
bool palindrome(int n) {
    // Write your code here
    int result = 0;
    int tempN = n;
    while (n != 0) {
        result = result * 10 + n % 10;
        n = n / 10;
    }
    if (result == tempN) {
        return true;
    }
    return false;
}

int main() {
    int input;
    std::cin >> input;
    std::cout << "Palindrome is: " << palindrome(input) << std::endl;
    return 0;
}