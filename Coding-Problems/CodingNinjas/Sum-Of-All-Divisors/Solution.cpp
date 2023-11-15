#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
You are given an integer 'n'.

Function 'sumOfDivisors(n)' is defined as the sum of all divisors of 'n'.

Find the sum of 'sumOfDivisors(i)' for all 'i' from 1 to 'n'.

Example:
Input: 'n' = 5
Output: 21

Explanation:
We need to find the sum of 'sumOfDivisors(i)' for all 'i' from 1 to 5.
'sumOfDivisors(1)' = 1
'sumOfDivisors(2)' = 2 + 1 = 3
'sumOfDivisors(3)' = 3 + 1 = 4
'sumOfDivisors(4)' = 4 + 2 + 1 = 7
'sumOfDivisors(5)' = 5 + 1 = 6

Therefore our answer is sumOfDivisors(1) + sumOfDivisors(2) + sumOfDivisors(3) +
sumOfDivisors(4) + sumOfDivisors(5) = 1 + 3 + 4 + 7 + 6 = 21

Sample Input 1:
3


Sample Output 1:
8


Explanation of sample output 1:
We need to find sumOfDivisors(1) + sumOfDivisors(2) +sumOfDivisors(3).
sumOfDivisors(1) = 1
sumOfDivisors(2) = 2 + 1 = 3
sumOfDivisors(3) = 3 + 1 = 4
Therefore, the answer is sumOfDivisors(1) + sumOfDivisors(2) + sumOfDivisors(3)
= 1 + 3 + 4 = 8.

Sample Input 2:
10


Sample Output 2:
87


Expected Time Complexity:
Try to solve this in O(sqrt(‘n’)).


Constraints:
1 <= ‘n’ <= 3*10^4

Time Limit: 1 sec

 */
int sumOfDivisors(int n) {
    /*
    To find a divisor, we need to run a loop from 1 to n
    See if its divisible by the current number
    If it is add it to a variable called sum
    Return sum
    */
    int sum = n;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int sumOfAllDivisors(int n) {
    // Write your code here
    /*
    Run a loop from 1 to n, call it i
    Get the sum of Divisors for that number, sumOfDivisors(i)
    Add this to a result variable
    Return result
    */
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += sumOfDivisors(i);
    }
    return result;
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    // std::vector<int> numbers(arr, arr + (sizeof(arr) / sizeof(int)));
    // for (size_t i = 0; i < numbers.size(); i++) {
    //     std::cout << sumOfDivisors(numbers[i]) << std::endl;
    // }
    int input;
    std::cin >> input;
    std::cout << sumOfAllDivisors(input) << std::endl;
    return 0;
}