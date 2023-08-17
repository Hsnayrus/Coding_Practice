#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent, with the colors in the
order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and
blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra
space?
*/
class Solution {
  private:
    template <typename T>
    void pushToFront(std::vector<T>& nums, std::vector, T element) {}

  public:
    void sortColors(std::vector<int>& nums) {
        size_t last0Index = SIZE_T_MAX;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                continue;
            } else if (nums[i] == 1) {
                if (last0Index == SIZE_T_MAX) {
                }
            }
        }
    }
};