// POTD
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
     
        unordered_map<int,int> vals;
        
        for(int i = 0;i<nums.size();i++){
            
            if(vals[nums[i]]){
                vals[nums[i]] ++;
            }else{
                vals[nums[i]] = 1;
            }
        }
        int result = 0;
        for(auto it : vals){
            int val = it.second;
            if(val == 1) return -1;
            if(val % 3 == 0) result += (val/3);
            else result += (val/3)+1;
        }
        return result;
    }
};