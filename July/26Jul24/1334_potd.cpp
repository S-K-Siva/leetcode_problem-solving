// A Star Algorithm (AI algorithms)

// class Solution {
// public:

//     void A_Star(vector<bool>& visited, vector<vector<int>>& adjLst, map<pair<int,int>,int>& trackCost, vector<int>& path, int node, int currentCost, int target, vector<int>& resultSize) {
//     if (currentCost > target) return;
//     if (currentCost == target) {
//         int pathSize = path.size();
//         if (pathSize) {
//             resultSize[0] = min(resultSize[0], pathSize);
//         }
//         return;
//     }
//     visited[node] = true;
    
//     for (auto it : adjLst[node]) {
//         if (!visited[it] && currentCost + trackCost[{node, it}] <= target) {
//             path.push_back(it);
//             A_Star(visited, adjLst, trackCost, path, it, currentCost + trackCost[{node, it}], target, resultSize);  // Pass 'it' as the new 'node'
         
//         }
//     }
    
//     visited[node] = false;  // Reset the visited status for backtracking
// }

//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> adjLst(n,vector<int>());
//         map<pair<int,int>,int> trackCost;

//         for(int i = 0;i<edges.size();i++){
//             adjLst[edges[i][0]].push_back(edges[i][1]);
//             adjLst[edges[i][1]].push_back(edges[i][0]);
//             trackCost[{edges[i][0],edges[i][1]}] = edges[i][2];
//             trackCost[{edges[i][1],edges[i][0]}] = edges[i][2];
//         }

//         for(int i = 0;i<n;i++){
//             cout << i << " : ";
//             for(auto it : adjLst[i]){
//                 cout << it << " ";
//             }cout << endl;
//         }

//         vector<int> result(1,0);
//         int minimumPathSize = n-1;
//         for(int i = 0;i<n;i++){
//             cout << "Node :" << i << endl;
//             vector<int> path;
//             vector<bool> visited(n,false);
//             vector<int> resultSize(1,0); // PathSize
           
//             A_Star(visited,adjLst,trackCost,path,i,0,distanceThreshold,resultSize);
//             cout << "PathsSize : " << resultSize[0]<<endl;
            
//             if(resultSize[0] < minimumPathSize){
//                 result[0] = i;
//                 minimumPathSize = resultSize[0];
//             }else if(resultSize[0] == minimumPathSize){
//                 result[0] = max(result[0],i);
//             }
//         }
//         return result[0];
//     }
// };

/*
1) A Star Algorithm Misalignment
2) Didn't use appropriate Data Structure to store edges with weight
3) Didn't take care of visited array in proper manner since it's correct in one way.
4) Should use priority queue, where my previous code is combination of dfs + (AI Algorithm) A Star and avoid recursive calls.
*/

vector<int> a_star(int start, const vector<vector<pair<int, int>>>& adjLst, int n) {
    vector<int> distances(n, INT_MAX);
    distances[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentNode]) continue;

        for (const auto& neighbor : adjLst[currentNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (currentDistance + edgeWeight < distances[nextNode]) {
                distances[nextNode] = currentDistance + edgeWeight;
                pq.emplace(distances[nextNode], nextNode);
            }
        }
    }
    
    return distances;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjLst(n);
        
        // Construct adjacency list
        for (const auto& edge : edges) {
            adjLst[edge[0]].emplace_back(edge[1], edge[2]);
            adjLst[edge[1]].emplace_back(edge[0], edge[2]);
        }

        int resultCity = -1;
        int minimumReachableCities = INT_MAX;
        
        // Evaluate each city
        for (int i = 0; i < n; i++) {
            vector<int> distances = a_star(i, adjLst, n);
            int reachableCities = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && distances[j] <= distanceThreshold) {
                    reachableCities++;
                }
            }

            if (reachableCities < minimumReachableCities) {
                minimumReachableCities = reachableCities;
                resultCity = i;
            } else if (reachableCities == minimumReachableCities) {
                resultCity = max(resultCity, i);
            }
        }

        return resultCity;
    }
};
