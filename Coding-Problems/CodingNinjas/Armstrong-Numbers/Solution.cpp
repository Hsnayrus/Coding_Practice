#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
You are given an integer 'n'.

Return 'true' if 'n' is an Armstrong number and 'false' otherwise.

Note:
An armstrong number is a number(with 'k' digits) such that the sum of its digits
raised to the 'kth' power is equal to the number itself. For Example, 371 is an
armstrong number because 3^3 + 7^7 + 1^3 = 371.

Example:
Input: 'n' = 1634
Output: True
Explanation:
1634 is an Amrstrong number as, 1^4 + 6^4 + 3^4 + 4^4 = 1634




Sample Input 1 :
1


Sample Output 1 :
true


Explanation of Sample Input 1 :
1 is an Armstrong number as, 1^1 = 1.


Sample Input 2 :
103


Sample Output 2 :
false


Expected Time Complexity:
Try to solve this in O(log(n)).


Constraints:
1 <= ‘n’ <= 10^9

Time Limit: 1 sec

 */
int getDigits(int n) {
    int digits = 0;
    do {
        digits++;
        n = n / 10;
    } while (n > 0);
    return digits;
}
bool checkArmstrong(int n) {
    // Write your code here
    // Get the number of digits
    // For each number, raise it to the digits the number has
    // Add it to a number named result.
    // If result == n; return true else false
    int digits = getDigits(n);
    int result = 0;
    int tempN = n;
    while (n > 0) {
        result += pow(int(n % 10), digits);
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
    std::cout << checkArmstrong(input) << std::endl;
    return 0;
}