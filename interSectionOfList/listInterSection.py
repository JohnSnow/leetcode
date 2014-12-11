#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):

        if not headA or not headB:
            return None

        countA = 0
        countB = 0
        listA = headA
        listB = headB

        while listA.next :
            countA += 1
            listA = listA.next

        while listB.next :
            countB += 1
            listB = listB.next

        # listA point to the longer list
        if countA < countB:
            listA = headB
            listB = headA
            countA, countB = countB, countA
        else:
            listA = headA
            listB = headB


        diff = countA - countB
        for i in xrange(0, diff):
            listA = listA.next

        for i in xrange(0, countB):
            if listA is listB:
                return listB
            listA = listA.next
            listB = listB.next
        return None

def test():
    """docstring for test"""
    elemA = ['a1', 'a2']
    elemB = ['b1', 'b2', 'b3']
    elemC = ['c1', 'c2', 'c3']

    headC = createNodeList(elemC)
    headA = createNodeList(elemA, headC)
    headB = createNodeList(elemB, headC)

    sl = Solution()
    node = sl.getIntersectionNode(headA, headB)
    print  node.val


def createNodeList(elemList, append = None):
    """docstring for createNodeList"""
    prev = head = None
    for item in elemList:
        cur = ListNode(item)
        if not head:
            head = cur
        else:
            prev.next = cur
        prev = cur

    if append:
        prev.next = append

    return head

if __name__ == '__main__':
    test()
