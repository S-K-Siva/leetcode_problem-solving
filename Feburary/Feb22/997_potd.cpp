#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mp;
        unordered_map<int,int> tr;
    
        for(auto it : trust){
            mp[it[0]]=1;
            tr[it[1]] += 1;
    
        }
        for(int i = 1;i<=n;i++){
            if(mp[i] == 0 && tr[i] == n-1) return i;
        }
        return -1;
    }
    // int findJudge(int n, vector<vector<int>>& trust) {
    //     unordered_map<int, int> store1;
    //     unordered_map<int, int> store2;

    //     for(int i = 0; i<trust.size(); i++){
    //         store1[trust[i][0]] = 1;
    //         store2[trust[i][1]]+=1;
    //     }

    //     for(int i = 1; i<=n; i++){
    //         if(store1[i] == 0 && store2[i] == n-1){
    //             return i;
    //         }
    //     }

    //     return -1;
    // }
    
};