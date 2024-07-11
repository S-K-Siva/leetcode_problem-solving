#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int maxim = 2147483648;
        vector<int> arr(3,0);
        arr[1] = 1;
        arr[2] = 1;
        int length = 3;
        for(int i = 3;i<n+1;i++){
            arr.push_back(((arr[length-1]%maxim)+(arr[length-2]%maxim)+(arr[length-3]%maxim))%INT_MAX);
            ++length;
        }
        return arr[n];
    }
};