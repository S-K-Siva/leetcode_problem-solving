class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(edges.empty() && n == 1) return 0;
        vector<int> nodes;
        for(int i = 0;i<n;i++){
            nodes.push_back(i);
        }

        for(auto it : edges){
            int weaker = it[1];

            if(find(nodes.begin(),nodes.end(),weaker) != nodes.end()){
                nodes.erase(remove(nodes.begin(),nodes.end(),weaker),nodes.end());
            }
        }

        return nodes.size() == 1 ? nodes[0] : -1;
    }
};
