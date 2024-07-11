#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int ex = numExchange;
        int cnt = n;
        if(n <= ex){
            if(n == ex) return n+1;
            return n;
        }

        while(n >= ex){
            cnt += (n/ex);
            n = (n/ex) + (n%ex); 

        }
        return cnt;
    }
};