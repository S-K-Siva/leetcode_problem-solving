#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2 == 0 && q%2 == 0){
            p/=2;
            q/=2;
        }
        if(p%2 == 0 && q%2 != 0) return 2;
        else if(p%2 != 0 && q%2 != 0) return 1;
        else return 0;
    }
};
