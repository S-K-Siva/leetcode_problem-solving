#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int prefix = 0;

        unordered_map<int,int> mp;

        mp[0] = 1;

        for(int i = 0;i<nums.size();i++){
            prefix += nums[i];
            cnt += mp[prefix - goal];
            mp[prefix]++;
        }
        return cnt;
    }
};