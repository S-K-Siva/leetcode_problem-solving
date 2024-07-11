#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vals(nums.size()+1,1);
        vals[0] = 0;
        unordered_map<int,int> mp;
        for(auto it : nums){
            if(vals[it]) vals[it] = 0;
            if(mp[it]) mp[it] ++;
            else mp[it] = 1;
        }
        
        int missingNumber = -1;
        for(int i = 0;i<vals.size();i++){
            if(vals[i] == 1){
                missingNumber = i;
                break;
            }
        }
        for(auto it : mp){
            if(it.second == 2){
                return {it.first,missingNumber};
            }
        }
        return {-1};
    }
};