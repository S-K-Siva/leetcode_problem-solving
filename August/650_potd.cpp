#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;

        vector<int> dp(n+1,0);
        dp[1] = 1;

        for(int i = 2;i<=n;i++){
            dp[i] = i;
            for(int j = 1;j<=(i/2);j++){
                if(i%j == 0){
                    int copies = i/j;
                    dp[i] = min(dp[i],dp[j] + copies);
                }
            }
        }
        return dp[n];
    }
};
