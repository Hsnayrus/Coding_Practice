"""
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.



Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.


Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.

Leetcode Question: 1790
"""
from typing import *
import re


class Solution:
    def convertStringToList(self, stringToConvert: str) -> List[str]:
        return re.findall("[a-zA-Z0-9]", stringToConvert)

    def listsAreSimilar(self, list1: List[str], list2: List[str]) -> bool:
        list1.sort()
        list2.sort()
        if list1 != list2 or len(list1) != len(list2):
            return False
        return True

    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        list_s1 = self.convertStringToList(s1)
        list_s2 = self.convertStringToList(s2)
        count = 0
        for i in range(0, len(list_s1)):
            if list_s1[i] != list_s2[i]:
                count = count + 1
        if not self.listsAreSimilar(list_s1, list_s2) or count > 2:
            return False
        return True
