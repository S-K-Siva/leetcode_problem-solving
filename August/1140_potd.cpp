#include<bits/stdc++.h>
using namespace std;

// ref
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // Step 1: Calculate suffix sums
        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // Step 2: Initialize DP table
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Step 3: Fill DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                // If all remaining piles can be taken
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                } else {
                    // Try taking 1 to 2*m piles
                    for (int x = 1; x <= 2 * m; ++x) {
                        dp[i][m] = max(dp[i][m], suffix[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }

        // Step 4: Return the result starting from the 0th pile and M = 1
        return dp[0][1];
    }
};
