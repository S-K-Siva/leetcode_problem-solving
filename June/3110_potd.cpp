#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;

        for(int i = 0;i<s.size()-1;i++)
        {
            result += abs(int(s[i]) - int(s[i+1]));
        }
        return result;
    }
};