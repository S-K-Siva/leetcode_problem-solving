// Issue : It removes duplicates,but it's removes few possibilities as well and time complexity is exponential!
// class Solution {
// public:
//     void helper(vector<int>& arr,vector<int>& res, int current, int k,int index,int n){
//         if(index == n)return;

//         if(current < k){
//             if(find(res.begin(),res.end(),current) == res.end())
//                 res.push_back(current);
//         }

//         for(int i = index;i<n;i++){
//             helper(arr,res,current+arr[i],k,i+1,n);
//             helper(arr,res,current,k,i+1,n);
//         }
//     }
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         vector<int> res;
//         helper(nums,res,0,k,0,nums.size());
//         return res.size();
//     }
// };

#include<bits/stdc++.h>
using namespace std;

// MOST Optimal Solution -> O(n)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if(k == 0) return 0;


       int size = nums.size();
       int track = 1;
       int result = 0;


       int l,r;
       l = 0;
       r = 0;

       while(r < size){
        track *= nums[r];
        r++;

        // here we making sure that the subarray is always below the K
        while(l<r && track >= k){
            track /= nums[l];
            l++;
        }
        // we adding the length of it.
        result += (r-l);
       }
       return result;
    }
};