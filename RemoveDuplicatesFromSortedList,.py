class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h = head
        while h != None:
            if h.next == None:
                break
            while h.next.val == h.val:
                h.next = h.next.next
                if h.next == None:
                    break
            h = h.next
        return head