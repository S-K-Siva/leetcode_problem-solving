#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // TLE : 69/72
        // int K = k;
        // int index = 0;
        // int totalSize = chalk.size();
        // while(K > 0){
        //     if(K < chalk[index%totalSize]) break;
        //     K -= chalk[index%totalSize];
        //     index++;
        // }

        // return index%totalSize;


        long long totalSum = accumulate(chalk.begin(),chalk.end(),0LL);
        int hs = k%totalSum;

        for(int i = 0;i<chalk.size();i++){
            if(hs < chalk[i]){
                return i;
            }
            hs -= chalk[i];
        }

        return -1;
    }
};
