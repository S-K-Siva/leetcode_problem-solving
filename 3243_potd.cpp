// wrong ans (544/972)

// class Solution {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         vector<int> dp(n,1);
//         dp[n-1] = 0;
        
//         vector<int> result;
//         for(auto it : queries){
//             int src = it[0];
//             int des = it[1];
//             dp[src] = max(dp[src],des-src);
//             int start = 0;
//             int count = 0;
            
//             while(start < n-1){
//                 start += dp[start];
//                 ++count;
//             }
            
//             result.push_back(count);
//         }

//         return result;
//     }
// };


// graph rep
class Solution {
public:
    int bfs(vector<vector<int>>& adjLst,int n){
        vector<int> distance(n,INT_MAX);
        distance[0] = 0;
        queue<int> que;
        que.push(0);

        while(!que.empty()){
            int node = que.front(); 
            que.pop();
            for(auto neigh : adjLst[node]){
                if(distance[neigh] > distance[node] + 1){
                    distance[neigh] = distance[node] + 1;
                    que.push(neigh);
                }
            }
        }

        return distance[n-1] == INT_MAX ? -1 : distance[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> adjLst(n,vector<int>());

        for(int i = 0;i<n-1;i++){
            adjLst[i].push_back(i+1);
        }
        vector<int> result;
        int prev = n-1;
        for(auto it : queries){
            int src = it[0];
            int des = it[1];
            adjLst[src].push_back(des);
            
            int value = bfs(adjLst, n);
            if(value != -1){
                prev = value;
            }
            result.push_back(prev);
        }
        return result;
    }
};
