#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newListHead = nullptr;
        ListNode* newListTail = nullptr;
        ListNode* tempList1 = list1;
        ListNode* tempList2 = list2;
        while (tempList1 != nullptr && tempList2 != nullptr) {
            ListNode* temp = new ListNode();
            if (tempList1->val <= tempList2->val) {
                temp->val = tempList1->val;
                tempList1 = tempList1->next;
            } else {
                temp->val = tempList2->val;
                tempList2 = tempList2->next;
            }
            if (newListHead == nullptr) {
                newListHead = temp;
                newListTail = temp;
            } else {
                newListTail->next = temp;
                newListTail = newListTail->next;
            }
        }
        ListNode* remainingList = nullptr;
        if (tempList1 == nullptr) {
            remainingList = tempList2;
        } else {
            remainingList = tempList1;
        }
        while (remainingList != nullptr) {
            if (newListHead == nullptr) {
                newListHead = new ListNode(remainingList->val);
                newListTail = newListHead;
            } else {
                newListTail->next = new ListNode(remainingList->val);
                newListTail = newListTail->next;
            }
            remainingList = remainingList->next;
        }
        return newListHead;
    }
};

int main() {
    Solution s1;
    ListNode* first3 = new ListNode(4);
    ListNode* first2 = new ListNode(2, first3);
    ListNode* first1 = new ListNode(1, first2);

    ListNode* second3 = new ListNode(4);
    ListNode* second2 = new ListNode(3, second3);
    ListNode* second1 = new ListNode(1, second2);

    ListNode* result = s1.mergeTwoLists(first1, second1);
    ListNode* temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    return 0;
}
