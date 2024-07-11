#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
    

        for(auto it : nums){
            if(it == 0) continue;
            if(it > 0) pos++;
            else neg ++;
        }
        return max(pos,neg);
    }
};