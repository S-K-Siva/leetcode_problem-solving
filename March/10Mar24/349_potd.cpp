#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;

        for(auto it : nums1){
            ++mp1[it];
        }

        for(auto it : nums2){
            ++mp2[it];
        }
        vector<int> result;
        for(auto it : mp1){
            if(mp2[it.first]){
                result.push_back(it.first);
            }
        }

        return result;
    }
};