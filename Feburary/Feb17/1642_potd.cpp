#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TLE..
    // void helper(int count,vector<int> &maxi,int index,int n, vector<int>&arr,int bricks,int ladders){
        
    //     if(bricks < 0 || ladders < 0){
    //         return;
    //     }
        
    //     if(bricks == 0 && ladders == 0 && index < n-1){
    //         if(arr[index] >= arr[index+1] && index == 0){
    //             maxi[0] = 1;
    //         }
    //         else
    //             maxi[0] = max(maxi[0],count);
    //         return;
    //     }
    //     maxi[0] = max(maxi[0],count);
    //     if(index == n-1){
    //         maxi[0] = max(maxi[0],count);
    //         return;
    //     }
    //     if(arr[index] >= arr[index+1]){
    //         helper(count+1,maxi,index+1,n,arr,bricks,ladders);
    //     }else{
    //         helper(count+1,maxi,index+1,n,arr,bricks-abs(arr[index]-arr[index+1]),ladders);
    //         helper(count+1,maxi,index+1,n,arr,bricks,ladders-1);
    //     }
    //     return;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int> pq; 
        int i;
        for(i = 0;i<heights.size()-1;i++){
            if(heights[i+1]-heights[i] <= 0) continue;
            int val = heights[i+1]-heights[i];
            bricks -= val;
            pq.push(val);
            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if(ladders < 0){
                break;
            }
        }
        return i;

        // vector<int> maxii(1,0);
        // helper(0,maxii,0,heights.size(),heights,bricks,ladders);
        // return maxii[0];
    }
};