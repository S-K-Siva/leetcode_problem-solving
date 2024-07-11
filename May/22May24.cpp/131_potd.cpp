#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start += 1;
            end -= 1;
        
        }
        return true;
    }

    void helper(vector<vector<string>> &result, vector<string> &track, string s, int index){
        if(index == s.size()){
            result.push_back(track);
            return;
        }
        for(int i = index;i<=s.size();i++){
            if(isPalindrome(s,index,i)){
                track.push_back(s.substr(index,i-index+1));
                helper(result,track,s,i+1);
                track.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> track;

        helper(result,track,s,0);
        return result;
    }
};