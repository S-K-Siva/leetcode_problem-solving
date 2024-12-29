// TLE (30/90)
// class Solution {
// public:
//     int numWays(vector<string>& words, string target) {
        
//         unordered_map<char,vector<int>> ash;
//         for(auto word : words){
//             for(int i = 0;i<word.size();i++){
//                 ash[word[i]].push_back(i);
//             }
//         }

//         queue<pair<int,vector<int>>> que;
//         for(auto it : ash[target[0]]){
//             que.push({0,{it}});
//         }
//         vector<vector<int>> result;
        

//         while(!que.empty()){
//             pair<int,vector<int>> curr = que.front();
//             que.pop();

//             int index = curr.first;
//             vector<int> series = curr.second;
//             if(series.size() == target.size())
//             {
//                 result.push_back(series);
//                 continue;
//             }
//             for(auto it : ash[target[index+1]]){
//                 if(it > series.back()){
//                     series.push_back(it);
//                     que.push({index+1,series});
//                     series.pop_back();
//                 }
//             }
//         }

//         return result.size();
//     }
// };


class Solution {
public:
        long long int MOD = 1e9 + 7;
        int dfs(int i, int col, const string& target, const vector<vector<int>>& ash, vector<vector<int>>& memo, int MOD, int n, int end) {
                if (i == end) return 1;
                if (col == n) return 0;
                if (memo[i][col] != -1) return memo[i][col];
                long long ways = dfs(i, col + 1, target, ash, memo, MOD, n, end) % MOD;
                if (ash[col][target[i] - 'a'] > 0) {
                    ways += (long long)ash[col][target[i] - 'a'] * dfs(i + 1, col + 1, target, ash, memo, MOD, n, end) % MOD;
                    ways %= MOD;
                }
                return memo[i][col] = ways;
            }


    int numWays(vector<string>& words, string target) {
        
        int end = target.size();
        int n = words[0].size();

        vector<vector<int>> ahs(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                ahs[j][word[j] - 'a']++;
            }
        }

        vector<vector<int>> memo(end, vector<int>(n, -1));
        return dfs(0, 0, target, ahs, memo, MOD, n, end);
    }
    
};
