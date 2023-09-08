from typing import *

"""
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


"""


class Solution:
    def setToZero(self, startCoordinate: List[int], matrix: List[List[int]]):
        i = 0
        while i < len(matrix[0]):
            matrix[startCoordinate[0]][i] = 0
            i = i + 1
        i = 0
        while i < len(matrix):
            matrix[i][startCoordinate[1]] = 0
            i = i + 1

    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        coordinateList = []
        for m in range(0, len(matrix)):
            for n in range(0, len(matrix[m])):
                if matrix[m][n] == 0:
                    # Add elements to the list of coordinates containing zeroes
                    coordinateList.append([m, n])
        # Once we have traversed the list and noted the position of all the 0s
        # We can set all the rows and columns to 0
        for coordinate in coordinateList:
            self.setToZero(coordinate, matrix)


if __name__ == "__main__":
    s1 = Solution()
    matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    s1.setZeroes(matrix)
    for i in range(0, len(matrix)):
        print("")
        for j in range(0, len(matrix[i])):
            print(matrix[i][j])
