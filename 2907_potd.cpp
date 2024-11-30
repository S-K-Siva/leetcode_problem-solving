// TLE
// mistakes..
// 1) considering all nodes as starting node , which will be O(N!) TC.
// 2) not used efficient way of indegree and outdegree concept to find the starting node..
// 3) used deque(for pop_front), instead of vector(gives stack-like behaviour), which is inefficient use

// class Solution {
// public:
    
//     bool solve(vector<vector<vector<int>>>& result, vector<vector<int>> current, vector<bool>& visited,vector<vector<int>>& pairs, int n){
//         if(current.size() == n){
//             result.push_back(current);
//             return true;
//         }

//         for(int i = 0;i<n;i++){
//             if(!visited[i]){
//                     if(current.back()[1] == pairs[i][0]){
//                         visited[i] = true;
//                         current.push_back(pairs[i]);
//                         if(solve(result, current, visited,pairs,n)) return true;
//                         current.pop_back();
//                         visited[i] = false;
//                     }
//             }
//         }
//         return false;
//     }
//     vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
//         int n = pairs.size();
        
//         vector<vector<vector<int>>> result;
        
//         for(int i = 0;i<n;i++){
//             vector<bool> visited(n,false);
//             vector<vector<int>> current;
//             visited[i] = true;
//             current.push_back(pairs[i]);
//             if(solve(result,current,visited,pairs,n)) return result[0];
//             visited[i] = false;
//         }

//         return pairs;
//     }
// };

class Solution {
public:


    void dfs(vector<int>& path, map<int,vector<int>>& adjLst, int node){
        
        while(!adjLst[node].empty()){
            int neigh = adjLst[node].back();
            adjLst[node].pop_back();
            dfs(path,adjLst,neigh);
        }
        path.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        if(pairs.empty() || pairs.size() == 1) return pairs;

        map<int,vector<int>> adjLst;
        map<int,int> outDegrees, inDegrees;

        for(auto it : pairs){
            adjLst[it[0]].push_back(it[1]);
            outDegrees[it[0]]++;
            inDegrees[it[1]]++;
        }

        int start = pairs[0][0];
        for(auto it : adjLst){
            if(outDegrees[it.first] - inDegrees[it.first] == 1){
                start = it.first;
                break;
            }
        }
        vector<int> path;
        dfs(path,adjLst, start);
        
        vector<vector<int>> result;
        for(int i = path.size()-1;i>0;i--){
            result.push_back({path[i],path[i-1]});
        }
        return result;
    }
};
