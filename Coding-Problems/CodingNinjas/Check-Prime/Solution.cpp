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
A prime number is a positive integer that is divisible by exactly 2 integers, 1
and the number itself.

You are given a number 'n'.

Find out whether 'n' is prime or not.

Example:
Input: 'n' = =5
Output: YES
Explanation: 5 is only divisible by 1 and 5. 2, 3, and 4 do not divide 5.


Sample Input 1:
5


Sample Output 1:
YES


Explanation of sample input 1 :
5 is only divisible by 1 and 5. 2, 3 and 4 do not divide 5.


Sample Input 2:
6


Sample Output 2:
NO


Explanation of sample input 2 :
6 is divisible by 1, 2, 3, and 6. Therefore it is not a prime number.
Numbers having more than two factors are known as composite numbers.


Sample Input 3:
1


Sample Output 3:
NO


Explanation of sample input 3 :
1 is divisible only by 1, having only one factor. Therefore it is not a prime
number. 1 is neither a prime nor a composite number.


Expected time complexity :
The expected time complexity is O(sqrt('n')).


Constraints :
1 <= 'n' <= 10 ^ 9

Time limit: 1 second

 */
bool isPrime(int n) {
    // Write your code here
    /**
     * Run a loop form 2 to sqrt(n), inclusive. call it i.
     * If any number is divisible by i then return false
     * Once loop ends, return true
     */
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int arr[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
                 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << ": " << isPrime(nums[i]) << std::endl;
    }
    return 0;
}