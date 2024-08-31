#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> track(n, 0.0);
        track[start_node] = 1.0;

        for (int i = 0; i < n; i++) {
            bool vis = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double currentProb = succProb[j];

                if ((track[u] * currentProb) > track[v]) {
                    track[v] = track[u] * currentProb;
                    vis = true;
                }
                if ((track[v] * currentProb) > track[u]) {
                    track[u] = track[v] * currentProb;
                    vis = true;
                }
            }
            if (!vis) break;
        }

        return track[end_node];
    }
};
