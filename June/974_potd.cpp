#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        // Worst Case : O(n^2)
        // for(int i = 0;i<n;i++){
        //     int tot = 0;
        //     for(int j = i;j<n;j++){
        //         tot += nums[j];
        //         if(tot % k == 0) cnt++;
        //     }
        // }

        // Optimal Solution : O(N)
        // Approach : Prefix Sum
        int total = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0;i<nums.size();i++){
            total += nums[i];
            int rem = total % k;
            // To handle negative values
            if (rem < 0){
                rem += k;
            }
            if(mp[rem])
            {
                cnt += mp[rem];
                ++mp[rem];
            }else{
                mp[rem] = 1;
            }
        }
        return cnt;
    }
};