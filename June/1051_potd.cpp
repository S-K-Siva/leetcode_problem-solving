#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr;
        arr = heights;
        int cnt = 0;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++){
            if(heights[i] != arr[i]) cnt++;
        }
        return cnt;
    }
};