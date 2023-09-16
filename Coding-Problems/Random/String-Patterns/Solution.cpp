#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given the length of a word(wordLen) and the maximum number of consecutive vowels
that it can contain(maxVowels), determine how many unique words can be
generated. Words will consist of English alphabetic letters a through z only.
Vowels are v: {a, e, i, o, u}. Consonants are the remaining 21 letters. In the
explanation, c and v represent consonants and vowels respectively.

Explanation:

wordLen = 1
maxVowels = 1
        Patterns: {v, c}
        That means there are 26 possibilities, one for each letter in the
alphabet.

wordLen = 4
maxVowels = 1
        Patterns: {cccc, cccv, ccvc, cvcc, vccc, cvcv, vcvc, vccv}

        (21 * 21 * 21 * 21) = 194481;
        (21 * 21 * 21 * 5) + (21 * 21 * 5 * 21) + (21 * 5 * 21 * 21) +(5 * 21 *
                21 * 21) = 185220;

                (5 * 21 * 21 * 5) + (21 * 5 * 21 * 5) + (5 * 21 * 21 * 5) =
11025

Since the output can be very long, return the answer modulo 1000000007
 */
class Solution {
    size_t getStringPatterns(int wordLen, int maxVowels) {}
};