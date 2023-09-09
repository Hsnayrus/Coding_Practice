#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>

template <typename T> void printList(std::vector<T> list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
}

class Solution {
  public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() < 3) {
            std::reverse(nums.begin(), nums.end());
        } else {
            int breakpoint = INT_MIN;
            for (size_t i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    breakpoint = i;
                    break;
                }
            }
            if (breakpoint == INT_MIN) {
                std::reverse(nums.begin(), nums.end());
            } else {
                for (size_t i = nums.size() - 1; i > breakpoint; i--) {
                    if (nums[i] > nums[breakpoint]) {
                        std::swap(nums[breakpoint], nums[i]);
                        break;
                    }
                }
                std::reverse(nums.begin() + breakpoint + 1, nums.end());
            }
            // Find an element greater than the one at breakpoint
        }
    }
};

int main() {
    Solution s1;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    printList(nums);
    std::cout << "\n";
    s1.nextPermutation(nums);
    std::cout << "\n";
    printList(nums);
}
