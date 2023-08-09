from typing import *

"""
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
"""


class Solution:
    def recurPermutations(self,
                          nums: List[int],
                          all_permutations: List[List[int]],
                          frequency_list: List[bool],
                          current_permutation: List[int]):
        if len(nums) == len(current_permutation):
            all_permutations.append(current_permutation.copy())

        for i in range(0, len(nums)):
            if not frequency_list[i]:
                current_permutation.append(nums[i])
                frequency_list[i] = True
                self.recurPermutations(
                    nums, all_permutations, frequency_list, current_permutation)
                current_permutation.pop(len(current_permutation) - 1)
                frequency_list[i] = False

    def findAllPermutations(self, nums: List[int]) -> List[List[int]]:
        frequency_list = [False for i in range(len(nums))]
        all_permutations = []
        current_permutation = []
        nums.sort()
        self.recurPermutations(nums, all_permutations,
                               frequency_list, current_permutation)
        return all_permutations

    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        Find all the permutations
        Sort them if not already sorted(if the list is already sorted, then 
        we don't need to sort the final list)
        Find the next Permutation, if there is no next, return the first one
        """
        all_permutations = self.findAllPermutations(nums.copy())
        i = 0
        while True:
            print("hello")
            if nums == all_permutations[i]:
                try:
                    nums = all_permutations[i + 1]
                except IndexError:
                    nums = all_permutations[0]
                break
            i = i + 1


if __name__ == "__main__":
    s1 = Solution()
    s1.nextPermutation([1, 2, 3])
