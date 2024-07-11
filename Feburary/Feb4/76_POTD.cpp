#include<bits/stdc++.h>
using namespace std;

// using two-pointer concept......

class Solution {
public:
    string minWindow(string s, string t) {
        int low=0,high=0;
        int best = 1e9,start = 0;
        unordered_map<int,int> freq_T,freq_s;
        for(auto it : t){
            if(freq_T[it]) ++freq_T[it];
            else freq_T[it] = 1;
        }

        while(low<=high && high < s.size()){
            ++freq_s[s[high++]];
            while(true){
                bool possible=true;
                for(auto it : freq_T){
                    if(freq_s[it.first] < it.second){
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
                if(possible && high-low < best){
                    best = high-low;
                    start = low;
                    
                }
                --freq_s[s[low++]];
            }
            
        }
        cout << start << " "<<best << endl;
        cout << low << " "<<high<<endl;
        // while(low > high){
        //     bool possible=true;
        //     for(auto it : freq_T){
        //         if(freq_s[it.first] < it.second){
        //             possible = false;
        //             break;
        //         }
        //     }
        //     if(possible && high-low < best){
        //         best = high-low;
        //         start = low;
        //     }
        
        //     --freq_s[low++];
        // }
        if(best == 1e9) return "";
        else return s.substr(start,best);
    }
};