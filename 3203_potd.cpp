class Solution {
public:
    void maxDis(int node, vector<vector<int>>& adj, vector<int>& vis, int current, int& maxi, int& mm) {
        vis[node] = 1;
        if(current > maxi){
            maxi = current;
            mm = node;
        }
 
        for (auto it : adj[node]) {
            if (!vis[it]) {
                maxDis(it, adj, vis, current + 1, maxi,mm);
            }
        }
     
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();

        vector<vector<int>> adj1, adj2;
        adj1.resize(n + 1);
        adj2.resize(m + 1);

        for (auto it : edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto it : edges2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        
        vector<int> vis1(adj1.size(), 0);
        vector<int> vis2(adj2.size(), 0);

        int maxi1 = 0, maxi2 = 0;
        int sk1 = 0,sk2 = 0;
        maxDis(0, adj1, vis1, 0, maxi1,sk1);
        vis1 = vector<int>(adj1.size(),0);
        maxi1 = 0;
        maxDis(sk1,adj1,vis1,0,maxi1,sk1);
        
        
        maxDis(0, adj2, vis2, 0, maxi2,sk2);
        vis2 = vector<int>(adj2.size(),0);
        maxi2 = 0;
        maxDis(sk2, adj2, vis2, 0, maxi2,sk2);
        
    
        return max(maxi1, max(maxi2, ((maxi1 + 1)/2) + ((maxi2 + 1)/2) + 1));
    }
};
