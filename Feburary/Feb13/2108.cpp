#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto str: words){
            int ans = true;
            int l = 0;
            int r =str.size()-1;
            while(l < r){
                if(str[l] != str[r]){
                    ans = false;
                    break;
                }
                l++;
                r--;
            }
            if(ans) return str;

        }
        return "";
    }
};