"""
You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).

 

Example 1:

Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
Output: 2
Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.
Example 2:

Input: x = 3, y = 4, points = [[3,4]]
Output: 0
Explanation: The answer is allowed to be on the same location as your current location.
Example 3:

Input: x = 3, y = 4, points = [[2,3]]
Output: -1
Explanation: There are no valid points.
 
Leetcode Question: 1779
"""
from typing import *
import math


class Solution:
    def getManhattanDistance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)

    def isAValidPoint(self, x: int, y: int, currentPoint: List[int]) -> bool:
        if x == currentPoint[0] or y == currentPoint[1]:
            return True
        return False

    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        smallest_distance = 65535
        result_index = -1
        for point in points:
            if self.isAValidPoint(x, y, point):
                distance = self.getManhattanDistance(x, y, point[0], point[1])
                if distance < smallest_distance or smallest_distance == 65535:
                    smallest_distance = distance
                    result_index = points.index(point)
        return result_index
