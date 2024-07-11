#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // TC : log N
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int l = 0;
        // int r = n-1;
        // if(nums[n-1] != n) return n;
        // while(l < r){
        //     if(nums[l]+1 == nums[l+1] && nums[r]-1 == nums[r-1]){
        //         l++;
        //         r--;
        //     }else{
        //         if(nums[l+1] != nums[l]+1) return nums[l]+1;
        //         if(nums[r-1] != nums[r]-1) return nums[r]-1;
        //     }
        // }
        // return 0;

        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // if(nums[n-1] != n) return n;
        // for(int i = 0;i<n;i++){
        //     if(nums[i] != i) return i;
        // }
        // return n;


        int n = nums.size();
        sort(nums.begin(),nums.end());
       
        int num;
        for(int i = 0;i<n;i++){
            if(nums[i] != i){
                num = i;
                break;
            }
        }
        return num;
    }
};