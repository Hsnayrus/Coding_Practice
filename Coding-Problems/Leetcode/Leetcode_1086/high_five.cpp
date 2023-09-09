#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> highFive(std::vector<std::vector<int>> &items) {
    std::vector<std::vector<int>>::iterator itemsIterator = items.begin();
    std::vector<std::vector<int>> result;
    std::map<int, std::priority_queue<int>> idScoresMap;
    while (itemsIterator != items.end()) {
      int key = (*itemsIterator)[0];
      int newScore = (*itemsIterator)[1];
      idScoresMap[key].push(newScore);
      ++itemsIterator;
    }
    std::map<int, std::priority_queue<int>>::iterator idScoresIterator =
        idScoresMap.begin();
    // std::sort(idScoresMap.begin(), idScoresMap.end());
    while (idScoresIterator != idScoresMap.end()) {
      int sum = 0;
      int key = idScoresIterator->first;
      std::priority_queue<int> scores = idScoresIterator->second;
      for (int i = 0; i < 5; i++) {
        sum += scores.top();
        scores.pop();
      }
      result.push_back({key, sum / 5});
      ++idScoresIterator;
    }
    return result;
  }
};

int main() {
  std::vector<std::vector<int>> testCase = {
      {1, 91}, {1, 92}, {2, 93},  {2, 97},  {1, 60}, {2, 77},
      {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}};
  Solution s1;
  std::vector<std::vector<int>> result;
  result = s1.highFive(testCase);
  for (std::vector<std::vector<int>>::iterator resultIterator = result.begin();
       resultIterator != result.end(); ++resultIterator) {
    std::cout << (*resultIterator)[0] << ", " << (*resultIterator)[1]
              << std::endl;
  }
}