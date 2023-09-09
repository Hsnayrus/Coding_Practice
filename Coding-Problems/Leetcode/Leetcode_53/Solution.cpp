#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/*
Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another
solution using the divide and conquer approach, which is more subtle.
*/
template <typename T> void printList(const std::vector<T>& list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

class Solution {
  public:
    int maxSubArray(std::vector<int>& nums) {
        /*
                Optimal Solution
        */
        int maxSum = nums[0];
        int currentSum = nums[0];
        if (nums.size() == 1) {
            return currentSum;
        }
        for (size_t i = 1; i < nums.size(); i++) {
            if (currentSum < 0) {
                currentSum = 0;
            }
            currentSum += nums[i];
            if (maxSum < currentSum) {
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution s1;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    // nums.push_back(-3);
    // nums.push_back(12);
    // nums.push_back(-11);
    // nums.push_back(-13);
    // nums.push_back(14);
    // nums.push_back(5);
    // nums.push_back(-2);
    std::cout << s1.maxSubArray(nums) << std::endl;
}
