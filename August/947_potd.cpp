

class Solution {
public:

    void dfs(int node, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited) {
    visited.insert(node);
    
    for (int neighbor : adjList[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adjList, visited);
        }
    }
}

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> adjList;
        
        for (const auto& stone : stones) {
            int x = stone[0], y = stone[1];
            if (adjList.find(x) == adjList.end()) {
                adjList[x] = vector<int>();
            }
            if (adjList.find(~y) == adjList.end()) {
                adjList[~y] = vector<int>();
            }
            adjList[x].push_back(~y);
            adjList[~y].push_back(x);
        }
        
        unordered_set<int> visited;
        int components = 0;
        
        for (const auto& stone : stones) {
            int x = stone[0];
            if (visited.find(x) == visited.end()) {
                dfs(x, adjList, visited);
                components++;
            }
        }
        
        return stones.size() - components;
    }
};
