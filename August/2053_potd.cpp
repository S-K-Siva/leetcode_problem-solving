#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            ++mpp[arr[i]];
        }

        int index = 1;
        for(int i = 0;i<n;i++){
            if(mpp[arr[i]] == 1){
                if(index == k) return arr[i];
                ++index;
            }
        }
        return "";
    }
};