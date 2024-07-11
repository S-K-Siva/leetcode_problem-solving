#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i = 0;i<s.size();i++){
            if(mp[s[i]]) mp[s[i]]++;
            else mp[s[i]] = 1;
        }

        vector<pair<int,char>> vals;
        for(auto it : mp){
            vals.push_back(make_pair(it.second,it.first));
        }
        sort(vals.begin(),vals.end());
        reverse(vals.begin(),vals.end());

        for(int i = 0;i<vals.size();i++){
            for(int j = 0;j<vals.size();j++){
                if(i == j) continue;
                if(vals[i].first == vals[j].first){
                    if(vals[i].second < vals[j].second){
                        swap(vals[i],vals[j]);
                    }
                }
            }
        }
        string resultString = "";
        for(auto it : vals){
            int cnt = it.first;
            while(cnt--){
                resultString += it.second;
            }
        }
        return resultString;

    }
};