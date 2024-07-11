#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void helper(vector<int> &result,vector<int> &arr,vector<int> &ss, int index,int n,int total){
    //     if(index >= n){
    //         result[0] = max(result[0],total);
    //         return;
    //     }

    //     for(int i = index;i<n;i++){
    //         ss.push_back(arr[i]);
    //         helper(result,arr,ss,i+2,n,total + arr[i]);
    //         ss.pop_back();
    //     }

    // }
    // int rob(vector<int>& nums) {
    //     vector<int> result(1,0);
    //     vector<int> ss;
    //     helper(result,nums,ss,0,nums.size(),0);
    //     return result[0];
    // }


    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    // Create an array to store intermediate results
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[n] = 0;
    dp[n - 1] = nums[n - 1];

    // Fill the array bottom-up
    for (int i = n - 2; i >= 0; i--) {
        // Decide whether to rob the current house or not
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }

    return dp[0];
}
};