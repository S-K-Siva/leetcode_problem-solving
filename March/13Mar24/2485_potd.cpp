#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        for(int i = 0;i<n;i++){
            int number = i+1;
            int left = (number * (number+1))/2;
            int right = (n*(n+1))/2;
            right -= left;
            right += number;

            if(left == right) return number;
        }

        return -1;
    }
};