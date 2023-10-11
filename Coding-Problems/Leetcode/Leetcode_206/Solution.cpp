#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given the head of a singly linked list, reverse the list, and return the
reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively.
Could you implement both?
 */

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution {
  private:
  public:
    ListNode * reverseList(ListNode * head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode * last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

int main() {
    ListNode * first5 = new ListNode(5);
    ListNode * first4 = new ListNode(4, first5);
    ListNode * first3 = new ListNode(3, first4);
    ListNode * first2 = new ListNode(2, first3);
    ListNode * first1 = new ListNode(1, first2);

    Solution s1;
    ListNode * newHead = s1.reverseList(first1);

    ListNode * temp = newHead;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr) {
            std::cout << "->";
        } else {
            std::cout << std::endl;
        }
        temp = temp->next;
    }
    return 0;
}
