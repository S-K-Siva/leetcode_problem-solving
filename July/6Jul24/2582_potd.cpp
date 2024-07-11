#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        if(time <= n){
            if(time == n){
                return n-1;
            }else{
                return time+1;
            }
        }
            int turns = time/(n-1);
            int track = time%(n-1);
            if(turns&1){
                return n - track;
            }
            return 1 + track;

        
    }
};