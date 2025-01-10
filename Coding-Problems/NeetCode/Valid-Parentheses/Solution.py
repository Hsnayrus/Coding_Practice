from typing import *
"""
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

    Every open bracket is closed by the same type of close bracket.
    Open brackets are closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true

Example 2:

Input: s = "([{}])"

Output: true

Example 3:

Input: s = "[(])"

Output: false

Explanation: The brackets are not closed in the correct order.

Constraints:

    1 <= s.length <= 1000

"""


class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0 or len(s) < 2:
            return False

        bracket_map = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        visited = []
        for b in s:
            # This is a closing bracket
            if b not in bracket_map:
                # The first bracket is a closed one
                if len(visited) == 0:
                    return False
                elif bracket_map[visited[len(visited) - 1]] != b:
                    # Unmatched, bracket, return False
                    return False
                else:
                    # Matched the closing bracket with a corresponding open bracket
                    visited.pop()
            else:
                visited.append(b)

        return visited == []
