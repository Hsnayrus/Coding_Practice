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
Determine if a given string 'S' is a palindrome using recursion. Return a
boolean value of true if it is a palindrom and false if it is not.

Note: You are not requierd to print anything, just implement the function.

Example:

Input:
s = "racecar"

Output:
True

Explanation:
"racecar" is a palindrome

Sample Input 1:
abbba
Sample Output 1:
true
Explanation Of Sample Input 1 :
“abbba” is a palindrome
Sample Input 2:
abcd
Sample Output 2:
false
Explanation Of Sample Input 2 :
“abcd” is not a palindrome.
Constraints:
0 <= |S| <= 10^6
where |S| represents the length of string S.

 */
// // Recursive solution
// bool isPalindrome(std::string& str) {
//     // Write your code here
//     if (str.size() < 2) {
//         return true;
//     }
//     if (str[0] != str[str.size() - 1]) {
//         return false;
//     }
//     std::string newString(str.begin() + 1, str.begin() + str.size() - 1);
//     return isPalindrome(newString);
// }

// Iterative solution
bool isPalindrome(std::string& str) {
    // Write your code here
    for (size_t i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string string;
    std::cin >> string;
    std::cout << "IsPalindrom: " << isPalindrome(string) << std::endl;
    return 0;
}