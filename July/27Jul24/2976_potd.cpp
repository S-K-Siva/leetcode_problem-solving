#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }
        int n = original.size();
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int weight = cost[i];
            adj[u][v] = min(weight,adj[u][v]);
        }
        for (int h = 0; h < 26; h++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][h] < INT_MAX && adj[h][j] < INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][h] + adj[h][j]);
                    }
                }
            }
        }
        long long result = 0;
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v)
                continue;
            if (adj[u][v] == INT_MAX)
                return -1;
            int weight = adj[u][v];
            result+=weight;
        }
        return result;
    }
};