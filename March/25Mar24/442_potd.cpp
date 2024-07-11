#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> res;
        unordered_map<int,int> mp;

        for(auto it : nums){
            if(mp[it]){
                if(!res[it]){
                    res[it] = 1;
                }
            }else{
                mp[it] = 1;
            }
        }

        vector<int> result;
        for(auto it : res){
            result.push_back(it.first);
        }
        sort(result.begin(),result.end());
        return result;
    }
};