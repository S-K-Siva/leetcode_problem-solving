#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<pair<int,int>> temp;

        for(auto it : nums){
            ++freq[it];
        }
        int total_size = 0;
        for(auto it : freq){
            total_size += it.second;
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),[&](pair<int,int> p1, pair<int,int> p2){
            if(p1.first == p2.first){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        });
        vector<int> result;
        result.reserve(total_size);
        for(auto it : temp){
            fill_n(back_inserter(result),it.first,it.second);
        }        
        return result;
        
    }
};