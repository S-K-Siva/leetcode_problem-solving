#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorry;

        for(auto it : queries){
            int left = arr[it[0]];
            for(int i = it[0]+1;i<=it[1];i++)
            {
                left ^= arr[i];
            }
            
            xorry.push_back(left);
        }

        return xorry;
    }
};
