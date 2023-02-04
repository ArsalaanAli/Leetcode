# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        q = PriorityQueue()
        count = 0
        for l in lists:
            count+=1
            if l:
                q.put((l.val, count, l))
        head = ListNode(None, None)
        cur = head
        while not q.empty():
            val, idx, node = q.get()
            if(node):
                cur.next = node
                if node.next:
                    count+=1
                    q.put((node.next.val, count, node.next))
                cur = cur.next
        return head.next