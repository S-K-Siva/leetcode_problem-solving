#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<string> &result, int index, int n, string s, string cur,unordered_map<string,int> mp){
        if(index >= n){
            result.push_back(cur.substr(0,cur.size()-1));
            return;
        }
        string new_track = "";
        for(int i = index;i<n;i++){
            new_track += s[i];
            if(mp[new_track]){
                helper(result, i+1,n,s,cur + new_track + " ",mp);
            }
            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int > mp;
        for(auto it : wordDict){
            ++mp[it];
        }
        vector<string> result;
        helper(result,0,s.size(),s,"",mp);
        sort(result.begin(),result.end());
        return result;
    }
};