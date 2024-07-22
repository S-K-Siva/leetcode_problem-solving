#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,int> ss;
        int n = names.size();
        for(int i = 0;i<n;i++){
            ss[heights[i]] = i;
        }
        vector<string> result;
        for(auto it : ss){
            result.push_back(names[it.second]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};