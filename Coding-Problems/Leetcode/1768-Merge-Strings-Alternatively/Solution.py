from typing import *
"""
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

"""

"""
Algo Mk1:
* Initialize i = 0
* result = ""
* while(true)
* result += word1[i] 
* result += word2[i]
* i += 1
* if i == len(word1) || i == len(word2):
* break
* If i == len(word1):
* result += word2[i:-1]
* else
* result += word1[i: -1]
* return result

DR1 Mk1: 
abcd
pqrs
i = 0
result = ""

result = a
result = ap
i = 1
dont break

result = apb
result = apbq
i = 2
dont break

result = apbqc
result = apbqcr
i = 3
dont break

result = apbqcrd
result = qpbqcrds
i = 4
i == len(word1)
break

i == len(word1)
result = apbqcrds + word[4:-1]

DR2 Mk1:
abc
pq

i = 0
result = ""

result = a
result = ap
i = 1
dont break

result = apb
result = apbq
i = 2
break since i == len(word2) = 2
2 != 3
result = apbq + word1[2:-1] = apbq + c

Algo Mk2:
* Initialize i = 0
* result = ""
* while(true)
* result += word1[i] 
* result += word2[i]
* i += 1
* if i == len(word1) || i == len(word2):
* break
* If i == len(word1):
* result += word2[i:]
* else
* result += word1[i:]
* return result
"""


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        if word1 == "":
            return word2
        if word2 == "":
            return word1
        i = 0
        result = []
        while True:
            result.append(word1[i])
            result.append(word2[i])
            i += 1
            if i == len(word1) or i == len(word2):
                break
        if i == len(word1):
            result.append(word2[i:])
        else:
            result.append(word1[i:])
        return "".join(result)
