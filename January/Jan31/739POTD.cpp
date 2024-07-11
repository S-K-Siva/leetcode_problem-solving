#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute Force : TLE (47&48 Testcases)
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();
    //     vector<int> ans(n,0);

    //     for(int i = 0;i<n;i++){
    //         int index = i+1;
    //         while(index < n){
    //             if(temperatures[index] > temperatures[i]){
    //                 ans[i] = index-i;
    //                 break;
    //             }
    //             index++;
    //         }
    //     }
    //     return ans;
    // }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = n-1;i>-1;i--){
            while(!s.empty() and s.top().first<=temperatures[i]){
                s.pop();
            }
            if(s.size() && s.top().first > temperatures[i]){
                ans[i] = s.top().second-i;
            }
            s.push({temperatures[i],i});
        }
        return ans;
    }
};