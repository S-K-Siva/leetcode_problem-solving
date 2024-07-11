#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(vector<vector<int>>& result, vector<int> nums,vector<int>& track,int n ,int index){
        if(index > n){
            return;
        }
        if(find(result.begin(),result.end(),track) == result.end()){
            result.push_back(track);
        }
        for(int i = index;i<n;i++){
            track.push_back(nums[i]);
            helper(result,nums,track,n,i+1);
            track.pop_back();
            helper(result,nums,track,n,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        helper(res,nums,track,nums.size(),0);
        sort(res.begin(),res.end());
        return res;
    }
};