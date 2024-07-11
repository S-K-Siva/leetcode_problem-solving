#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        for(int i = 0;i<n;i++){
          total |= nums[i];
        }
        return total << (n-1);
    }
};

/*
It seems a magic to use this formula. Althought LC gives an explanation with examples, but without proof. Hereby will try to prove for the simple case.

Let's consider very simple case. nums={p,q}nums=\{p, q\}nums={p,q} it has subsets
{},{p},{q},{p,q}\{\}, \{p\}, \{q\}, \{p, q\}{},{p},{q},{p,q}
where n=len(nums)=2. The xorsum is
xorsum=p+q+p^q
Consider the table

p   q   xorsum  p or q
0   0   0       0
0   1   2       1   
1   0   2       1
1   1   2       1
In this case it is true that xorsum=orSum(nums)*2^{n-1}
*/