class Solution:
    def climbStairs(self, n: int) -> int:
        lst = [1,2]
        if n == 1:
            return lst[0]
        elif n == 2:
            return lst[1]
        else:
            for i in range(3,n+1):
                lst.append(lst[-1]+lst[-2])
        return lst[-1]