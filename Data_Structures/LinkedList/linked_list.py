from typing import *


class SinglyLinkedList():
    class _Node():
        def __init__(self, data, next=None):
            self.data = data
            self.next = next

    def __init__(self, data=None):
        self._head = self._Node(data=data)
        self._size = 0

    @property
    def head(self):
        return self._head

    @property
    def size(self):
        return self._size

    def add_front(self, data):
        self._head = self._Node(data=data, next=self._head)
        self._size += 1

    def __len__(self):
        return self._size

    def __str__(self):
        result = ""
        temp = self._head
        while temp is not None:
            result += str(temp.data)
            if temp.next is not None:
                result += "\n"
            temp = temp.next
        return result


if __name__ == "__main__":
    my_list = SinglyLinkedList(5)
    print(str(my_list))
    my_list.add_front(4)
    print(str(my_list))
