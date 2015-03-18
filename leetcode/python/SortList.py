# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def quickSortList(self, head):
        # one element
        if head == None:
            return None

        base = head
        head = head.next

        p = ListNode(-1); q = ListNode(-1)
        while not head == None: 
            if head.val <= base.val:
                temp = ListNode(head.val)
                temp.next = p.next
                p.next = temp
            elif head.val > base.val:
                temp = ListNode(head.val)
                temp.next = q.next
                q.next = temp

            head = head.next

        # sort respectively
        p = self.quickSortList(p.next)
        q = self.quickSortList(q.next)

        # merge
        head = None
        if not p == None:
            head = p
            while not p.next == None:
                p = p.next
            p.next = base
        else:
            head = base

        base.next = q
        return head

    def sortList(self, head):
        if head == None:
            return None
        if head.next == None:
            return head

        # calculate the length
        p = head
        length = 0
        while not p == None:
            p = p.next
            length = length+1

        # split
        mid = length/2

        p = head; i = 0
        while i < mid-1:
            p = p.next
            i = i+1

        q = p.next
        p.next = None

        head = self.sortList(head)
        q = self.sortList(q)

        # merge
        if head.val<q.val:
            reHead = head
            reQ = q
        else:
            reHead = q
            reQ = head

        temp = reHead
        while reQ != None:
            if temp.next == None:
                temp.next = reQ
                break
            if reQ.val < temp.next.val:
                needInsert = reQ
                reQ = reQ.next

                needInsert.next = temp.next
                temp.next = needInsert
            temp = temp.next    
        return reHead

    def printList(self, head):
        while not head == None:
            print head.val,
            head = head.next
        print 
      
s = Solution()

l = [5, 8, 89, 10, -254, 89, 78]

head = ListNode(l[-1])

for i in range(len(l)-1):
    node = ListNode(l[i])
    node.next = head.next
    head.next = node    

head = s.sortList(head)

while not head == None:
    print head.val,
    head = head.next
