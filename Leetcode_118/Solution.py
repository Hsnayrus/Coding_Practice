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
    def generateElement(self, row: int, column: int) -> int:
        # Assuming that row and column are 0-indexed
        result = 1
        for i in range(0, column):
            result = result * (row - i)
            result = result / (i + 1)
        return int(result)

    def generateRow(self, rowNumber: int) -> List[int]:
        result = 1
        tempList = []
        tempList.append(result)
        for i in range(1, rowNumber):
            result = result * (rowNumber - i)
            result = result / i
            tempList.append(int(result))
        return tempList

    def generate(self, numRows: int) -> List[List[int]]:
        pTList = []
        for row in range(1, numRows + 1):
            pTList.append(self.generateRow(row))
        return pTList


if __name__ == "__main__":
    s1 = Solution()
    print(s1.generate(6))
