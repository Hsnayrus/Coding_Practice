#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing
order, and two integers m and n, representing the number of elements in nums1
and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the
last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
from nums1. Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to
ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109


Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/
template <typename T> void printList(std::vector<T> list) {
    for (typename std::vector<T>::iterator it = list.begin(); it != list.end();
         ++it) {
        std::cout << *it;
        if (it != list.end()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

class Solution {
  public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m, nums1.end());
        // If either is zero, return the other one.
        if (nums1.size() == 0) {
            nums1 = nums2;
        } else {
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < nums1.size(); j++) {
                    if (nums2[i] < nums1[j]) {
                        nums1.insert(nums1.begin() + j, nums2[i]);
                        break;
                    } else if (j == nums1.size() - 1) {
                        nums1.push_back(nums2[i]);
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    int array[] = {1};
    int array2[] = {1};
    std::vector<int> first(array, array + sizeof(array) / sizeof(int));
    std::vector<int> second(array2, array2 + sizeof(array2) / sizeof(int));
    Solution s1;
    s1.merge(first, 3, second, 3);
    printList(first);
}
