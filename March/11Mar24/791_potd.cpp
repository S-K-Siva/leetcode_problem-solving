#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string customSortString(string order, string s) {
        string result_string = "";
        vector<int> vec(26,0);
        
        for(int i = 0;i<s.size();i++){
            ++vec[s[i] - 'a'];
        }

        for(int i = 0;i<order.size();i++){
            if(vec[order[i]-'a']){
                for(int j = 0;j<vec[order[i] - 'a'];j++){
                    result_string += order[i];
                }
                vec[order[i] - 'a'] = 0;
            }
        }

        for(int i = 0;i<26;i++){
            while(vec[i]--){
                result_string += (i+'a');
            }
        }
        return result_string;
    }
};