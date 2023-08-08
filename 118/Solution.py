from typing import *

"""
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
"""


class Solution:
    def generateNthRow(self, row: int, pTriangle: List[List[int]]):
        tempList = [1]
        for i in range(0, row - 1):
            tempList.append(pTriangle[row - 1][i] + pTriangle[row - 1][i + 1])
        tempList.append(1)
        return tempList

    def generate(self, numRows: int) -> List[List[int]]:
        pTList = [[1]]
        if numRows == 1:
            return pTList
        pTList.append([1, 1])
        if numRows > 2:
            for i in range(2, numRows):
                pTList.append(self.generateNthRow(i, pTList))
        return pTList


if __name__ == "__main__":
    s1 = Solution()
    print(s1.generate(1))
