#include "myHeader.hpp"
#include <set>
/*
Given an array of integers arr, return true if the number of occurrences of each
value in the array is unique or false otherwise.



Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values
have the same number of occurrences. Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true


Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
 */
class Solution {
  public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> frequencyTable;
        std::set<int> frequencySet;
        for (size_t i = 0; i < arr.size(); i++) {
            frequencyTable[arr[i]]++;
        }
        for (std::unordered_map<int, int>::iterator it = frequencyTable.begin();
             it != frequencyTable.end(); ++it) {
            frequencySet.insert(it->second);
        }
        return frequencySet.size() == frequencyTable.size();
    }
};