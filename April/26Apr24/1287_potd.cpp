#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(auto it : arr){
            ++mp[it];
        }

        for(auto it : mp){
            double ans = (float)(it.second * 100)/arr.size();
            
            if(ans >= 25.00) return it.first;
        }
        return arr[0];
    }
};