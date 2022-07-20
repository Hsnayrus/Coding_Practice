#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > highFive(std::vector<std::vector<int> > & items) {
    std::map<int, std::vector<int> > studentScores;
    std::vector<std::vector<int> >::iterator itemsIterator = items.begin();
    while (itemsIterator != items.end()) {
      std::vector<int>::iterator subIterator = (*itemsIterator).begin();
      while (subIterator != (*itemsIterator).end()) {
        std::cout << *subIterator << " ";
        ++subIterator;
      }
      std::cout << "\n";
      ++itemsIterator;
    }
    std::vector<std::vector<int> > result;
    return result;
  }
};

int main() {
  std::vector<std::vector<int> > testCase = {{1, 91},
                                             {1, 92},
                                             {2, 93},
                                             {2, 97},
                                             {1, 60},
                                             {2, 77},
                                             {1, 65},
                                             {1, 87},
                                             {1, 100},
                                             {2, 100},
                                             {2, 76}};
  Solution s1;
  std::vector<std::vector<int> > result;
  result = s1.highFive(testCase);
}