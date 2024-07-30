#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> Stack;
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(Stack.empty()){
                Stack.push(s[i]);
            }else{
                char topElement = Stack.top();
                if(topElement == 'b' && s[i] == 'a'){
                    cnt++;
                    Stack.pop();
                }else{
                    Stack.push(s[i]);
                }
            }
        }
        return cnt;
    }
};