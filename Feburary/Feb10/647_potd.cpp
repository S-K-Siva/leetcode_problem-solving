#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = s.size();
        string arr = s;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int left = i , right = j;
                while(left < right){
                    if(arr[left] == arr[right]){
                        left++;
                        right--;
                    }else{
                        break;
                    }
                }
                if(left == right || left > right){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};