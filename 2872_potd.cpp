class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& values, vector<int>& vis, int node, int k, int& count) {
        vis[node] = 1;
        int remainder = values[node] % k;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                int child_remainder = dfs(adj, values, vis, neigh, k, count);
                remainder += child_remainder;
                remainder %= k;
            }
        }

        
        if (remainder == 0) {
            ++count;
            return 0;
        }

        return remainder;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        // int total = accumulate(values.begin(),values.end(),0);
        // if(total%k != 0) return 0;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        dfs(adj, values, vis, 0, k, count);

        return count;
    }
};
