#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> sss;

        int maxi = 0;
        int length = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                sss.push('(');
                ++length;
                maxi = max(maxi,length);
            }
            if(s[i] == ')' && !sss.empty() && sss.top() == '('){
                sss.pop();
                --length;
            }
        }

        return maxi;
    }
};