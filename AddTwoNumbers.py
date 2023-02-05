# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0)
        cur = head
        carry = 0
        while l1 or l2:
            if not l1:
                sum = l2.val + carry
            elif not l2:
                sum = l1.val + carry
            else:
                sum = l1.val + l2.val + carry
            if sum >= 10:
                carry = 1
                sum -= 10
            else:
                carry = 0
            cur.next = ListNode(sum)
            cur = cur.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry == 1:
            cur.next = ListNode(1)
        return head.next
            