# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def traverse(self,start,end,arr):
        if start > end:
            return
        mid = start + (end-start)//2
        root = TreeNode(arr[mid])

        root.left = self.traverse(start,mid-1,arr)
        root.right = self.traverse(mid+1,end,arr)
        return root

    def sortedArrayToBST(self, arr: List[int]) -> Optional[TreeNode]:
        return self.traverse(0,len(arr)-1,arr)


    # Time Complexity is O(N)
    # Space Complexity is O(Log(N))