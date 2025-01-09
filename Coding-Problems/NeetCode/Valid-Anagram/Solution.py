from typing import *
"""
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true

Example 2:

Input: s = "jar", t = "jam"

Output: false

Constraints:

    s and t consist of lowercase English letters.

"""


class Solution:
    def getCharacterFrequency(self, s: str) -> dict:
        result = {}
        for char in s:
            if result.get(char):
                result[char] += 1
            else:
                result[char] = 1
        return result

    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = self.getCharacterFrequency(s)
        t_dict = self.getCharacterFrequency(t)
        return s_dict == t_dict


if __name__ == "__main__":
    s1 = Solution()
    print(s1.isAnagram("racecar", "carrace"))
    print(s1.isAnagram("bhosadike", "dikebhos"))
    print(s1.isAnagram("no", "yes"))
    print(s1.isAnagram("", ""))
