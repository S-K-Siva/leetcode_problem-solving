#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long total = -1;
        long long  tot = nums[0]+nums[1];
        for(int i =2;i<nums.size();i++){
            if(tot > nums[i]){
                total = max(total,tot+nums[i]);
            }
            
            tot += nums[i];
        }
        return total;
    }
};