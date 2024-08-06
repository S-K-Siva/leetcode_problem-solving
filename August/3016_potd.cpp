#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        /*
        TC : O(N log N)
        SC : O(N)
        */
        unordered_map<char,int> charTrack;
        for(int i = 0;i<word.size();i++){
            ++charTrack[word[i]];
        }

        vector<pair<int,int>> sortByOccurance;
        for(auto it : charTrack){
            sortByOccurance.push_back({it.second,it.first});
        }

        sort(sortByOccurance.begin(),sortByOccurance.end());
        reverse(sortByOccurance.begin(),sortByOccurance.end());

        int index = 1;
        int size = 0;
        string ss = "";
        for(auto it : sortByOccurance){
            ss += it.second;
        }
        int ssSize = ss.size();
        int segments = ssSize / 8;
        int result = 0;

        unordered_map<char,int> keyDowns;
        for(int i = 0;i<ss.size();i++){
            keyDowns[ss[i]] = (i/8)+1;
        }

        for(int i = 0;i<ss.size();i++){
            result += charTrack[ss[i]] * keyDowns[ss[i]];
        }
        return result;

    }
};