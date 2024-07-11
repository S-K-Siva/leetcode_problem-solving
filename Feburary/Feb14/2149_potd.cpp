#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i = 0,j=1;
        for(int p = 0;p<nums.size();p++){
            if(nums[p]>=0){
                ans[i] = nums[p];
                i+=2;
            }else{
    
                    ans[j] = nums[p];
                    j+=2;
                
            }
        }
        return ans;
    }
};