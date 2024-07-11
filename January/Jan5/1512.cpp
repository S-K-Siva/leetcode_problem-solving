#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> vals;
        for(int i = 0;i<nums.size();i++){
            count += vals[nums[i]];
            vals[nums[i]]++;
        }
        return count;
    }
};