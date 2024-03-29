"""
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 
Leetcode Question: 1281
"""


class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sum = 0
        if n == 0:
            return 0
        while True:
            if n == 0:
                break
            r = n % 10
            product = product * r
            sum = sum + r
            n = int(n / 10)
        return product - sum
