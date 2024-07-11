#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int i = 0;i<arr.size();i++){
            if(mp[arr[i]]) mp[arr[i]]++;
            else{
                mp[arr[i]] = 1;
            }
        }
        
        vector<pair<int,int>> array;
        for(auto it : mp)
        {
            array.push_back({it.second,it.first});
        }
        sort(array.begin(),array.end());
        int K = k;
        for(int i = 0;i<array.size() && K > 0;i++){
            if(array[i].first - K <= 0){
                K-=array[i].first;
                mp.erase(array[i].second);
            }else{
                break;
            }
        }
        
        
        return mp.size();
        
    }
};