from typing import *
"""
Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.

Example 1:

Input: head = [0,1,2,3]

Output: [3,2,1,0]

Example 2:

Input: head = []

Output: []

Constraints:

    0 <= The length of the list <= 1000.
    -1000 <= Node.val <= 1000

"""
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current_node = head
        previous_node = None
        while current_node != None:
            next_node = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            if next_node == None:
                break
            else:
                current_node = next_node
        return current_node
