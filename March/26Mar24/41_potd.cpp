#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int iter = 0;

        while(iter < nums.size() && nums[iter] <= 0){
            iter++;
        }
        int number = 1;
        int i = iter;

        while(i < n){
            if(nums[i] != number) return number;
            while(i < n && nums[i] == number){
                i++;
            }
            

            number++;
            if(i >= n) break;
        }
        return number;
    }
};