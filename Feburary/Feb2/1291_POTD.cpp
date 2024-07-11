#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i = 1;i<10;i++){
            int val = i;
            int start = i+1;
            for(start;start < 10;start++){
                val *= 10;
                val += start;

                if(val >= low && val <= high){
                    result.push_back(val);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};