#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {

        if(s == "") return s;
        stack<char> ss;

        ss.push(s[0]);


        for(int i = 1;i<s.size();i++){
            if(isupper(s[i]) && !ss.empty()){
                char ch = ss.top();
                if(islower(ch) && toupper(ch) == s[i]){
                    ss.pop();
                    continue;
                }
                // else if(isupper(ch) && ch == s[i]){
                //     ss.pop();
                //     continue;
                // }
                else{
                    ss.push(s[i]);
                }
                // ss.push(s[i]);
            }
            else if(islower(s[i]) && !ss.empty()){
                char ch = ss.top();
                if(isupper(ch)){
                    if(tolower(ch) == s[i]){
                        ss.pop();
                        continue;
                    }else{
                        ss.push(s[i]);
                    }
                }
                else{
                    ss.push(s[i]);
                }
            }
            else{
                ss.push(s[i]);
            }
        }

        string result = "";

        while(!ss.empty()){
            char chh = ss.top();
            result += chh;
            ss.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};