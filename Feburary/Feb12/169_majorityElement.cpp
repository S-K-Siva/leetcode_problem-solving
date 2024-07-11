#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;

        for(int i = 1;i<nums.size();i++){
            if(nums[i] != element){
                --count;
                if(count == 0){
                    element = nums[i];
                    count = 1;
                }
            }else{
                ++count;
            }
        }
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == element){
                cnt++;
            }
        }
        if(cnt > (nums.size()/2)){
            return element;
        }
        return -1;
    }
};