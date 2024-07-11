#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int total_answer = 0;
        int track_answer = 0;

        int n = tokens.size();
        sort(tokens.begin(),tokens.end());

        int l = 0,h=n-1;

        while(l <= h){
            if(power >= tokens[l]){
                power -= tokens[l];
                track_answer+=1;
                total_answer = max(total_answer,track_answer);
                l+=1;
            }else if(track_answer > 0){
                power += tokens[h];
                track_answer -= 1;
                h--;
            }else{
                break;
            }
        }

        return total_answer;
    }
};