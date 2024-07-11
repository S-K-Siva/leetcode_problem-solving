#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        
        int left = 0;
        int right = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '*'){
                ++left;
            }else{
                if(left == 0 && s[i] == ')') return false;
                --left;
            }
        }

        for(int i = s.size()-1;i>-1;i--){
            if(s[i] == ')' || s[i] == '*'){
                ++right;
            }else{
                if(right == 0 && s[i] == '(') return false;
                --right;
            }
        }
        
        return true;
    }
};