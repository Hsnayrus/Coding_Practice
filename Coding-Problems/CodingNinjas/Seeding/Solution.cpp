#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
Sam is planting trees on the upper half region(separated by the left diagonal)
of the square shared field. For every value of 'N', print the field if the trees
are represented by "*".

Example:
Input: N = 3

Output:
* * *
* *
*

Detailed Explanation:
Input Format:
The first and only line contains an Integer, 'N'
Output Format:
Print the pattern as specified

Constraints:
1 <= T <= 10
1 <= N <= 25

Sample Input 1:
3
Sample Output 1:
* * *
* *
*
Sample Input 2 :
1
Sample Output 2 :
*
Sample Input 3 :
4
Sample Output 3 :
* * * *
* * *
* *
*

 */
void seeding(int n) {
    // Write your code here.
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}