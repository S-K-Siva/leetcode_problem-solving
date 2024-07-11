#include<iostream>
#include<vector>
#include<algorithm>
using namespaces std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n = digits.size()-1;
        int prev = 1;
        while(n>-1){
            result.push_back(((digits[n]+prev)%10));
            prev = (digits[n]+prev)/10;
            n--;
        }
        if(prev){
            result.push_back(prev);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};