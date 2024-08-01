#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        // for(auto it : details){
        //     string age = it.substr(11,2);
        //     int age = stoi(age);
        //     if(age > 60) res++;
        // }

        for(auto it : details){
            if(stoi(it.substr(11,2)) > 60) res++;
        }
        return res;
    }
};