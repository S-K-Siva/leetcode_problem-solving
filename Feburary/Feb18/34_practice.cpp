#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        vector<int> ans(2,-1);
        vector<int> vis(arr.size(),0);
        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == target){
                int m = mid;
                while(m > -1){
                    if(arr[m] == target){
                        m--;
                    }else{
                        break;
                    }
                }
                int mm = mid;
                while(mm < arr.size()){
                    if(arr[mm] == target){
                        mm++;
                    }else{
                        break;
                    }
                }

                ans[0] = m+1;
                ans[1] = mm-1;
                break;
            }else if(arr[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};