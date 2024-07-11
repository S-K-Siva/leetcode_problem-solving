#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        vector<int> visited(n,0);
        vector<string> myArr;
        for(int i = 0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            myArr.push_back(s);
        }
        for(int i =0;i<n;i++){
        
            if(!visited[i]){
                
                vector<string> res = {strs[i]};
                
                
                for(int j = i+1;j<n;j++){
                    if(!visited[j]){
                        if(myArr[i] == myArr[j]){
                            res.push_back(strs[j]);
                            visited[j] = 1;
                        }
                    }
                }
                result.push_back(res);
            }
        }
        return result;
    }
};