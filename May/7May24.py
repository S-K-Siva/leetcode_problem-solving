# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        lst = [head.val]

        temp = head.next
        while temp:
            while len(lst) and lst[-1] < temp.val:
                lst.pop()
            lst.append(temp.val)
            temp = temp.next
        
        res = ListNode(-1)
        temp = res
        for i in range(len(lst)):
            newNode = ListNode(lst[i])
            temp.next = newNode
            temp = temp.next
        
        return res.next
        