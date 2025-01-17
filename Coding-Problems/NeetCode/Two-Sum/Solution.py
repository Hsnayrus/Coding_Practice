from typing import *
"""
Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.

Example 1:

Input: 
nums = [3,4,5,6], target = 7

Output: [0,1]

Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

Example 2:

Input: nums = [4,5,6], target = 10

Output: [0,2]

Example 3:

Input: nums = [5,5], target = 10

Output: [0,1]

Constraints:

    2 <= nums.length <= 1000
    -10,000,000 <= nums[i] <= 10,000,000
    -10,000,000 <= target <= 10,000,000

"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited_map = {}
        for i, n in enumerate(nums):
            difference = target - n
            if difference in visited_map:
                return [visited_map[difference], i]
            visited_map[n] = i
        return []


if __name__ == "__main__":
    s1 = Solution()
    print(s1.twoSum([3, 4, 5, 6], 7))
    print(s1.twoSum([4, 5, 6], 10))
    print(s1.twoSum([5, 5], 10))
    print(s1.twoSum([9, 8, 1, 3, 4, 5, 34], 7))
