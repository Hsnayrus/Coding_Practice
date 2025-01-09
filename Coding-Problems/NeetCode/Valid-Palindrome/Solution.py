from typing import *
"""
Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true

Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:

Input: s = "tab a cat"

Output: false

Explanation: "tabacat" is not a palindrome.

Constraints:

    1 <= s.length <= 1000
    s is made up of only printable ASCII characters.

"""
"was it a car or cat I saw"


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.strip().split()
        s = ''.join(s).lower()
        first = 0
        second = len(s) - 1

        while (first < second):
            if not s[first].isalnum():
                first += 1
                continue
            if not s[second].isalnum():
                second -= 1
                continue

            if s[first] != s[second]:
                return False

            first += 1
            second -= 1

        return True
