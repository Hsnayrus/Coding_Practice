#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement
Sam is making a triangular painting for a maths project.
An N-dimensional Triangle is represented by the lower triangle of the pattern
filled with integers starting from 1. For every value of 'N', help sam to print
the corresponding N-dimensional Triangle.

Example:
Input: N = 3

Output:
1
1 2
1 2 3

Detailed Explanation:
Input Format:
The first and only line contains an integer, 'N'.

Output Format:
Print the pattern as specified

Sample Input 1:
3
Sample Output 1:
1
1 2
1 2 3
Sample Input 2 :
1
Sample Output 2 :
1

 */
void nTriangle(int n) {
    // Write your code here
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << j + 1 << " ";
        }
        std::cout << std::endl;
    }
}