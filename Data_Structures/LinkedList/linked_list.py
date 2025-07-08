from typing import *


class SinglyLinkedList():
    class _Node():
        def __init__(self, data, next=None):
            self.data = data
            self.next = next

        def __str__(self):
            return str(self.data)

    def __init__(self):
        self._head = None
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

    def add_back(self, data):
        new_node = self._Node(data=data, next=None)
        if self._head is None:
            self._head = new_node
        else:
            temp = self._head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node
        self._size += 1

    def remove_back(self):
        if self._head is None:
            return
        tail = self._head
        current = None
        while tail.next is not None:
            tail = tail.next
            if current is None:
                current = self._head
            else:
                current = current.next
        if current is None:
            result = self._head
            self._head = None
            self._size -= 1
        else:
            result = current.next
            current.next = None
            self._size -= 1
        return result

    def remove_front(self):
        if self._head is None:
            return None
        result = self._head
        self._head = result.next
        result.next = None
        return result

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


class DoublyLinkedList():
    class _Node():
        def __init__(self, data, next=None, prev=None):
            self.data = data
            self.next = next
            self.prev = prev

        def __str__(self):
            return str(self.data)

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    @property
    def head(self):
        return self._head

    @property
    def tail(self):
        return self._tail

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

    def __reversed__(self):
        temp = self._tail
        while temp is not None:
            yield temp
            temp = temp.prev

    def add_front(self, data):
        if data is None:
            return

        self._head = self._Node(data=data, next=self._head, prev=None)
        if self._head.next is not None:
            self._head.next.prev = self._head
        else:
            self._tail = self._head
        self._size += 1

    def add_back(self, data):
        self._tail = self._Node(data=data, next=None, prev=self._tail)
        self._size += 1
        if self._tail.prev is not None:
            self._tail.prev.next = self._tail
        else:
            self._head = self._tail

    def remove_back(self):
        # Empty List
        if self._tail is None:
            return None
        result = self._tail
        self._tail = self._tail.prev
        if self._tail is None:
            self._head = None
        else:
            self._tail.next = None
            result.prev = None
        self._size -= 1
        return result
