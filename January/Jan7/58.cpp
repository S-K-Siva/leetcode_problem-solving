#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.size()-1;i>-1;i--){
            if(length && s[i] == ' ') return length;
            if(s[i] == ' ')continue;
            else{
                length+=1;
            }
        }
        return length;
    }
};