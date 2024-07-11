#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> temp;
        for(auto it : strs){
            string s = it;
            sort(s.begin(),s.end());
            temp.push_back(s);
        }
        int n= strs.size();
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                vector<string> newArr;
                newArr.push_back(strs[i]);
                visited[i] = 1;
                for(int j = i+1;j<n;j++){
                    if(!visited[j]){
                        if(temp[i] == temp[j]){
                            newArr.push_back(strs[j]);
                            visited[j] = 1;
                        }
                    }
                }
                result.push_back(newArr);
            }
        }
        return result;
    }
};