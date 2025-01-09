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
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_count = [0] * 26

        for i in range(len(s)):
            char_count[ord(s[i]) - ord('a')] += 1
            char_count[ord(t[i]) - ord('a')] -= 1

        for count in char_count:
            if count != 0:
                return False
        return True


if __name__ == "__main__":
    s1 = Solution()
    print(s1.isAnagram("racecar", "carrace"))
    print(s1.isAnagram("bhosadike", "dikebhos"))
    print(s1.isAnagram("no", "yes"))
    print(s1.isAnagram("", ""))
