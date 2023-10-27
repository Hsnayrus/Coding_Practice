#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given a list arr of N integers, print sums of all subsets in it.

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
Your Task:
You don't need to read input or print anything. Your task is to complete the
function subsetSums() which takes a list/vector and an integer N as an input
parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
 */

template <typename T> void print(std::vector<T> currentVector) {
    for (size_t i = 0; i < currentVector.size(); i++) {
        std::cout << currentVector[i];
        if (i != currentVector.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

class Solution {
  public:
    std::vector<std::vector<int> >
    generateAllSubsets(const std::vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        std::vector<std::vector<int> > allSubsets;
        while (i < (1 << n)) {
            int j = 0;
            std::vector<int> currentSet;
            while (j < n) {
                if ((1 << j) & i) {
                    currentSet.push_back(nums[j]);
                }
                j++;
            }
            allSubsets.push_back(currentSet);
            i++;
        }
        return allSubsets;
    }

    template <typename T> T sumVector(const std::vector<T> &nums) {
        T result = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            result += nums[i];
        }
        return result;
    }

    std::vector<int> subsetSums(std::vector<int> arr, int N) {
        std::vector<std::vector<int> > allSubsets = generateAllSubsets(arr);
        std::vector<int> result;
        for (size_t i = 0; i < allSubsets.size(); i++) {
            result.push_back(sumVector(allSubsets[i]));
        }
        return result;
    }
};

int main() {
    int nums[] = {5, 1, 2};
    std::vector<int> numsV(nums, nums + sizeof(nums) / sizeof(int));
    Solution s1;
    std::vector<int> result = s1.subsetSums(numsV, numsV.size());
    print(result);
    return 0;
}
