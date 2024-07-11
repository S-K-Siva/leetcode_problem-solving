#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,int> m;
        
        for(int i = 0;i<s.size();i++){
            if(!mp[s[i]] && !m[t[i]]){
                mp[s[i]] = t[i];
                m[t[i]] = s[i];
            }else if(mp[s[i]]){
                if(m[t[i]] != s[i]) return false;
            }else if(m[t[i]]){
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};