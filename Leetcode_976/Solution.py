"""
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.



Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

Leetcode Question: 976
"""
from typing import *


class Solution:
    def formsTriangle(self, a: int, b: int, c: int) -> bool:
        if (a + b) > c and (c + a) > b and (b + c) > a:
            return True
        return False

    def largestPerimeter(self, nums: List[int]) -> int:
        """
            I need to find the combination of 3 highest sides which form
            a triangle.
            One idea is to sort, reverse the list then try the first two
            sides with a combination of
        """
        nums.sort()
        nums.reverse()
        index = 0
        while index < (len(nums) - 2):
            a = nums[index]
            b = nums[index + 1]
            c = nums[index + 2]
            if self.formsTriangle(a, b, c):
                return a + b + c
            index = index + 1
        return 0
