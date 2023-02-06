# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        used = set()
        while True:
            if head == None:
                return False
            if head in used:
                return True
            used.add(head)
            head = head.next
            