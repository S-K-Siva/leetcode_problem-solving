#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int val = -1;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int l1=0,l2=0;
        while(l1 < nums1.size() && l2 < nums2.size()){
            if(nums1[l1] == nums2[l2]){
                val = nums1[l1];
                break;
            }else if(nums1[l1] < nums2[l2]){
                l1++;
            }else{
                l2++;
            }
        }

        return val;
    }
};