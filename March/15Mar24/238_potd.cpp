#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        int n = nums.size();
        for(int i = 1;i<n;i++){
            left[i] *= nums[i-1] * left[i-1];
        }

        for(int j = n-2;j>-1;j--){
            right[j] *= nums[j+1] * right[j+1];
        }


        for(int i = 0;i<n;i++){
            nums[i] = left[i]*right[i];
        }

        return nums;

    }
};