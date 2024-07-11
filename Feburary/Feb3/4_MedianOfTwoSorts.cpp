#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto it : nums2){
            nums1.push_back(it);
        }
        sort(nums1.begin(),nums1.end());
        int size = nums1.size();
        if(size%2 == 0){
            int total = nums1[(size/2)-1] + nums1[size/2];
            return (double) total/2;
        }else{
            return (double) nums1[size/2];
        }
    }
};