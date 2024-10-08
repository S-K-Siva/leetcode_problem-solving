#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            long long MAX = 0;

            for(int j = i; j < min(i + k, n); j++){
                MAX = max(MAX, (long long)arr[j]);

                dp[i] = max(dp[i], (j - i + 1) * MAX + dp[j + 1]);
            }
        }

        return dp[0];
    }
};