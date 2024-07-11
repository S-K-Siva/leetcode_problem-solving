#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maximum_element = *max_element(nums.begin(),nums.end());
        int index = 0;
        int accept = true;
        for(int i = 0;i<nums.size();i++){
    
            if(nums[i] == maximum_element){
                index = i;
            }
        }
        for(int i = 0;i<nums.size();i++){
                if(nums[i]*2 > maximum_element && i!=index){
                    accept = false;
                    break;
                }
            }
        
        if(!accept) return -1;
        return index;
    }
};