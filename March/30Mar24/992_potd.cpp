#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(vector<int>&nums,int k){
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        int res = 0;
        int n= nums.size();
        while(j < n){
            ++mp[nums[j]];
            while(i <= j && mp.size() > k){
                if(mp[nums[i]] == 1) mp.erase(nums[i]);
                else --mp[nums[i]];
               
                i++;
            }
            
            res += (j-i+1);
            
            j++;
        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return helper(nums,k) - helper(nums,k-1);
    }
};