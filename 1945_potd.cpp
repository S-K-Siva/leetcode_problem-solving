#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getLucky(string s, int k) {
        string initial = "";

        for(long long int i = 0;i<s.size();i++)
        {
            initial += to_string(s[i] - 'a' + 1);
        }

        while(k > 0){
            long long int number = 0;
            for(long long int i = 0;i<initial.size();i++){
                number += initial[i] - '0';
            }
            initial = to_string(number);
            k--;
        }
        return stoi(initial);
    }
};
