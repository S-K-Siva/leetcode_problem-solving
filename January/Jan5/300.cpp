#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),pow(10,5));

        for(int i = 0;i<nums.size();i++){
            int findIndex = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(findIndex < nums.size()){
                dp[findIndex] = min(dp[findIndex],nums[i]);
            }
            
        }
        for(int i = nums.size()-1;i>-1;i--){
            if(dp[i] < 1e5){
                return i+1;
            }
        }
        return 0;
    }
};