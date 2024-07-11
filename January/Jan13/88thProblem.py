class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        temp = nums1[:m]
        
        num3 = temp + nums2
        num3 = sorted(num3)
       
        
        for i in range(m+n):
            nums1[i] = num3[i]

