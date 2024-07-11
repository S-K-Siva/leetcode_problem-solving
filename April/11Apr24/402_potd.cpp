#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<char> s;
        for(auto c :num){
            while(k>0 && !s.empty() && s.top()>c){
                s.pop();
                k-=1;
            }
            s.push(c);
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        string result="";
        while(!s.empty()){
            result+=s.top();
            s.pop();
        }
        reverse(result.begin(),result.end());
        int a=0;
        while(result[a]=='0' && a<result.size()){
            a++;
        }
        if(a==result.size()) return "0";
        string res="";
        for(int i=a;i<result.size();i++){
            res+=result[i];
        }
        return res;
    }
};