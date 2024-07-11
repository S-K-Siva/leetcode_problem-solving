#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto i:tasks) {
            freq[i-'A']++;
        }
        sort(freq.rbegin(),freq.rend());
        int blocks=(freq[0]-1)*n;
        for(int i=1;i<26;i++) {
            if(freq[i]==0) {
                break;
            }
            blocks-= min(freq[i],freq[0]-1);
        }
        if(blocks>0) {
            return tasks.size()+blocks;
        }
        else {
            return tasks.size();
        }
    }
};