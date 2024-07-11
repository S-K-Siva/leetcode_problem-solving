#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int track = 0;
        string res = "";
        for(int i = 0;i<s.size();i++){
                if(s[i] == '('){
                    track++;
                    res+=s[i];
                }
                else if(s[i] == ')' && track){
                        track--;
                        res+=s[i];
                }else{
                    if(s[i] != '(' && s[i] != ')')
                        res+=s[i];
                }
        }
        cout << res << endl;
        cout << track << endl;
        if(track > 0){
            int length = track;
            string result = "";
            int i;
            for(i = res.size()-1;i > -1&& length;i--){
                if(res[i] == '('){
                    --length;
                }else{
                    result += res[i];
                }
            }
            for(i;i>-1;i--){
                result += res[i];
            }
            reverse(result.begin(),result.end());
            cout << "res:"<<result<<endl;
            return result;
        }
        return res;
    }
};