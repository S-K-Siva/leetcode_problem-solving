class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        r = bin(right)[2:]
        n = len(r)
        l = bin(left)[2:].zfill(n)

        res = 0
        for i in range(n):
            if(r[i] != l[i]):
                return res
            if r[i] == "1":
                res |= (1 << (n-i-1))
        
        return res
        