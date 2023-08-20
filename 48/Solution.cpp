#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90
degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 */

template <typename T> void printList(std::vector<T> list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}
class Solution {
  public:
    void rotate(std::vector<std::vector<int> >& matrix) {
        std::vector<std::vector<int> > newMatrix;
        for (size_t i = 0; i < matrix.size(); i++) {
            newMatrix.push_back(std::vector<int>());
            for (size_t j = 0; j < matrix[i].size(); j++) {
                newMatrix[i].push_back(matrix[i][j]);
            }
        }
        size_t sizeRow = newMatrix.size() - 1;
        for (size_t i = 0; i < newMatrix.size(); i++) {
            for (size_t j = 0; j < newMatrix[i].size(); j++) {
                matrix[i][j] = newMatrix[sizeRow - j][i];
            }
        }
    }
};

int main() {
    Solution s1;
    std::vector<std::vector<int> > matrix;
    int myArray[] = {1, 2, 3};
    int secondRow[] = {4, 5, 6};
    int thirdRow[] = {7, 8, 9};
    std::vector<int> V1stRow(myArray, myArray + sizeof(myArray) / sizeof(int));
    std::vector<int> V2ndRow(secondRow,
                             secondRow + sizeof(secondRow) / sizeof(int));
    std::vector<int> V3rdRow(thirdRow,
                             thirdRow + sizeof(thirdRow) / sizeof(int));
    matrix.push_back(V1stRow);
    matrix.push_back(V2ndRow);
    matrix.push_back(V3rdRow);
    s1.rotate(matrix);
    for (size_t i = 0; i < matrix.size(); i++) {
        printList(matrix[i]);
    }
}
