#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<vector<int>>& result,vector<int>& track,vector<int>& candidates, int target, int current,int index, int n)
    {
        if(current > target || index > n){
            return;
        }
        if(current == target){
            if(find(result.begin(),result.end(),track) == result.end())
                result.push_back(track);
            return;
        }

        for(int i = index;i<n;i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(current + candidates[i] > target) break;
            track.push_back(candidates[i]); 
            solve(result,track,candidates,target,current + candidates[i], i+1,n);
            track.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> Track;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        solve(result,Track,candidates, target,0,0,n);   
        sort(result.begin(),result.end());
        return result;
    }
};