#include <cstdlib>
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
  /*
     Right is in the format [toAdd, coordinate],
     Left is the array on which the addition is happening
     Example:
     Left: {0, 0}; Right: {1, 1}
     This means add 1 to 2nd coordinate;
     */
  void add(std::vector<int> &left, std::vector<int> right) {
    left[right[1]] += right[0];
  }
  void turn(int &currentDirection, bool left) {
    currentDirection = currentDirection + (left ? 1 : -1);
    if (currentDirection < 0) {
      currentDirection = 3;
    } else if (currentDirection > 3) {
      currentDirection = 0;
    }
  }
  /*
    Each direction has a different coordinate to change and a different value to
    add. If initially at north, L changes to West, adding -1 to x coordinate L
    again then adding -1 to y coordinate L again then add 1 to x coordinate L
    again then add 1 to y coordinate What is a direction then? A direction is
    the way that the robot is facing. Each direction is a different way that the
    robot is headed. Following array is in the format [[toAdd, x/y]] where each
    sub element is a direction Move on x-axis is index 0, 1 for y-axis
    [north,  west,    south,   east]
    [[1, 1], [-1, 0], [-1, 1], [1, 0]]
    N->E: 11 to 10   : R 11 to 10
    E->S: 10 to -11  : R 10 to 01
    S->W: -11 to -10 : R 01 to 00
    W->N: -10 to 11  : R 00 to 11
    N->W: 11 to -10  : L 11 to 00
    W->S: -10 to -11 : L 00 to 01
    S->E: -11 to 10  : L 01 to 10
    E->N: 10 to 11   : L 10 to 11
    For R it goes in this direction: 11 -> 10 -> 01 -> 00 -> 11; 3 to 2 to 1 to
    0 to 3
    For L it goes in this direction: 11 -> 00 -> 01 -> 10 -> 11; 3 to 0
    to 1 to 2 to 3 N is 3; W is 0; S is 1; E is 2
    */
  bool isRobotBounded(std::string instructions) {
    if (instructions.size() == 0) {
      return false;
    }
    if (std::find(instructions.begin(), instructions.end(), 'L') ==
            instructions.end() &&
        std::find(instructions.begin(), instructions.end(), 'R') ==
            instructions.end()) {
      return false;
    }
    std::vector<int> coordinates = {0, 0};
    std::vector<std::vector<int>> directions = {
        {1, 1}, {-1, 0}, {-1, 1}, {1, 0}};
    int currentDirection = 0;
    for (int i = 0; i < instructions.size(); i++) {
      if (instructions[i] == 'L') {
        turn(currentDirection, true);
      } else if (instructions[i] == 'R') {
        turn(currentDirection, false);
      } else {
        add(coordinates, directions[currentDirection]);
      }
    }
    std::cout << "Start Location: (0, 0)\nEnd Location: (" << coordinates[0]
              << ", " << coordinates[1] << ")\n";
    if (currentDirection != 0 || (coordinates[0] == 0 && coordinates[1] == 0)) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s1;
  std::cout << (s1.isRobotBounded("GLGG") ? "Repeats" : "Doesn't Repeat")
            << std::endl;
  return 0;
}
