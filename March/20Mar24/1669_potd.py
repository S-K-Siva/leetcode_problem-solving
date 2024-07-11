# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        new_head1 = ListNode(-1, list1)
        new_head2 = ListNode(-1, list2)
        
        def find(head, x):
            current = head
            count = 0
            
            while current.next is not None and count < x:
                count += 1
                current = current.next
                
            return current
        
        def find_last(head):
            current = head
            
            while current.next is not None:
                current = current.next
                
            return current
        
        anode = find(new_head1, a)
        bnode_after = find(new_head1, b).next.next
        
        anode.next = list2
        list2_last = find_last(new_head2)
        
        list2_last.next = bnode_after
        
        return new_head1.next   