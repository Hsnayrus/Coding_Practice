#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
Sam is making a forset visualizer. An N-dimensional forest is represented by the
pattern of size NxN filled with '*'. An N/2-dimentional forest is represented by
the lower triangle of the pattern filled with '*'.

For every value of 'N', help sam to print the corresponding N/2-dimensional
forest. Example: Input: 'N' = 3

Output:
*
* *
* * *

Detailed Explanation:

Input Format:
The first and only line contains an integer 'N'.
Output Format:
Print the pattern as specified.

Constraints:
1 <= N <= 25
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
*
* *
* * *
Explanation Of Sample Input 1 :
For N = 3, fill all the rows and columns in the lower triangle of 3x3 matrix
with ‘*’. Sample Input 2 :
1
Sample Output 2 :
*

 */
void nForest(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}
