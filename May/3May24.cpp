#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        if(nums.size() == 1) return -1;
        int result = -1;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < 0 && mp[abs(nums[i])]){
                result = max(result,abs(nums[i]));
            }else{
                ++mp[nums[i]];
            }
        }
        return result;
    }
};