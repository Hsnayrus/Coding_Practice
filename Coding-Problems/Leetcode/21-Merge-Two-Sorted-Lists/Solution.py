from typing import *
"""
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

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
"""
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# # Naive Solution
# # Runtime: 0ms, 100%ile
# # Memory: 17.78MB, 61.32%ile


# class Solution:
#     def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
#         res_list = []
#         while list1 and list2:
#             if list1.val < list2.val:
#                 res_list.append(list1.val)
#                 list1 = list1.next
#             else:
#                 res_list.append(list2.val)
#                 list2 = list2.next

#         while list1:
#             res_list.append(list1.val)
#             list1 = list1.next

#         while list2:
#             res_list.append(list2.val)
#             list2 = list2.next

#         result = None
#         tail = None
#         for elem in res_list:
#             if not result:
#                 result = ListNode(elem)
#                 tail = result
#             else:
#                 tail.next = ListNode(elem)
#                 tail = tail.next
#         return result


# # Better Solution
# # Runtime: 0ms, 100%ile
# # Memory: 17.80MB, 61.32%ile
# class Solution:

#     def add_node(self, val):
#         node_to_add = ListNode(val)
#         if not self.head:
#             self.head = node_to_add
#             self.tail = self.head
#         else:
#             self.tail.next = node_to_add
#             self.tail = self.tail.next

#     def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
#         self.head = None
#         self.tail = self.head
#         while list1 and list2:
#             greater = None
#             if list1.val < list2.val:
#                 greater = list1.val
#                 list1 = list1.next
#             else:
#                 greater = list2.val
#                 list2 = list2.next
#             self.add_node(greater)

#         while list1:
#             self.add_node(list1.val)
#             list1 = list1.next

#         while list2:
#             self.add_node(list2.val)
#             list2 = list2.next

#         return self.head
