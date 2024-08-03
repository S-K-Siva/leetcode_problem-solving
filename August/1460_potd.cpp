#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        // Brute Force
        // TC : O(N)
        // SC : O(1)

        // unordered_map<int,int> mpp;

        // int n = arr.size();

        // for(int i = 0;i<n;i++){
        //     ++mpp[arr[i]];
        // }

        // for(int i = 0;i<target.size();i++){
        //     if(mpp[target[i]] == 1){
        //         mpp.erase(target[i]);
        //     }else if(mpp[target[i]]){
        //         --mpp[target[i]];
        //     }else{
        //         return false;
        //     }
        // }

        // return true;

        // Optimal
        // TC : O(N log n)
        // SC : O(1)

        sort(arr.begin(),arr.end()); // O(n log n)
        sort(target.begin(),target.end()); // O(n log n)
        int n = arr.size();
        for(int i = 0;i<n;i++){ // O(n)
            if(arr[i] != target[i]) return false;
        }
        return true;
    }
};