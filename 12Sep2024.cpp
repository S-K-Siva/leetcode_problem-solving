#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> mpp;

        for(int i = 0;i<allowed.size();i++){
            ++mpp[allowed[i]];
        }
        
        int cnt = 0;
        for(int i = 0;i<words.size();i++){
            string str = words[i];
            bool found = true;
            for(int i = 0;i<str.size();i++){
                if(!mpp[str[i]]){
                    found = false;
                    break;
                }
            }

            if(found) cnt++;
        }

        return cnt;
    }
};
