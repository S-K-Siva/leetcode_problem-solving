#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int prev = 2;
        int prev_prev = 1;
        for(int i = 2;i<n;i++){
            int newOne = prev + prev_prev;
           
            prev_prev = prev;
            prev = newOne;
        }
        return prev;
    }
};