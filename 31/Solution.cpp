#include <iostream>
#include <stdlib.h>
#include <vector>

class Solution {
  private:
    void recurPermute(std::vector<int> nums,
                      std::vector<std::vector<int> >& allPermutations,
                      std::vector<bool>& frequencyList,
                      std::vector<int>& currentPermutation) {
        if (nums.size() == currentPermutation.size()) {
            allPermutations.push_back(currentPermutation);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (frequencyList[i] != true) {
                frequencyList[i] = true;
                currentPermutation.push_back(nums[i]);
                recurPermute(nums, allPermutations, frequencyList,
                             currentPermutation);
                currentPermutation.pop_back();
                frequencyList[i] = false;
            }
        }
    }
    std::vector<std::vector<int> > findAllPermutations(std::vector<int> nums) {
        std::vector<int> currentPermutation;

        std::vector<bool> frequencyList;
        for (size_t i = 0; i < nums.size(); i++) {
            frequencyList.push_back(false);
        }

        std::vector<std::vector<int> > allPermutations;

        recurPermute(nums, allPermutations, frequencyList, currentPermutation);
        return allPermutations;
    }

  public:
    template <typename T> void printList(std::vector<T> list) {
        for (size_t i = 0; i < list.size(); i++) {
            std::cout << list[i] << " ";
        }
        std::cout << "\n";
    }
    void nextPermutation(std::vector<int>& nums) {
        std::vector<std::vector<int> > allPermutations;
        std::vector<int> temp(nums);
        std::sort(temp.begin(), temp.end());

        allPermutations = findAllPermutations(temp);
        // Print all Permutations

        for (size_t i = 0; i < allPermutations.size(); i++) {
            printList(allPermutations[i]);
        }

        for (size_t i = allPermutations.size() - 1; i >= 0; i--) {
            if (std::equal(nums.begin(), nums.end(),
                           allPermutations[i].begin())) {
                if (i == allPermutations.size() - 1) {
                    nums = allPermutations[0];
                } else {
                    nums = allPermutations[i + 1];
                }
                break;
            }
        }
    }
};

int main() {
    Solution s1;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    s1.printList(nums);
    std::cout << "\n";
    s1.nextPermutation(nums);
    std::cout << "\n";
    s1.printList(nums);
}
