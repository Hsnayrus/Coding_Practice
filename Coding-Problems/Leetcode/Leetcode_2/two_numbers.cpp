#include <stdio.h>
#include <stdlib.h>

#include <iostream>

struct ListNode {
  int val;
  ListNode * next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
    int temp = 0;
    ListNode * newHead;
    ListNode * tempL1 = l1;
    ListNode * tempL2 = l2;
    while (true) {
    }
  }
};