"""
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

Leetcode Question: 202
"""
from typing import *


class Solution:
    def numberToSumOfSquaredDigits(self, n: int) -> int:
        temp = n
        result = 0
        while True:
            if n < 1:
                break
            result = result + ((n % 10) * (n % 10))
            n = int(n / 10)
        return result

    def isHappy(self, n: int) -> bool:
        values_travelled = set()
        while n != 1 and n not in values_travelled:
            values_travelled.add(n)
            # Repeat the process until the number equals 1
            # Numbers ending in 1 are happy numbers
            # Replace the number with the sum of squares of its digits
            n = self.numberToSumOfSquaredDigits(n)
        # Return True if number is happy, False if not
        return n == 1
