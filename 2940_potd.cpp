class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> hs(n, -1); 

        stack<int> Stack;
        for(int i = n-1;i>=0;i--){
            while(!Stack.empty() && heights[Stack.top()] <= heights[i]){
                Stack.pop();
            }
            if(!Stack.empty()) hs[i] = Stack.top();
            Stack.push(i);
        }

        vector<int> ans;

        for (auto query : queries) {
            if(query[0] > query[1]){
                swap(query[0],query[1]);
            }
            int alice = query[0];
            int bob = query[1];

            if (alice == bob || heights[alice] < heights[bob] || bob == hs[alice]) {
                ans.push_back(bob);
                continue;
            }
            else if(hs[alice] == -1 || hs[bob] == -1){
                ans.push_back(-1);
                continue;
            }
            int maxi = max(hs[alice],hs[bob]);
            if(heights[maxi] > heights[alice] && heights[maxi] > heights[bob]){
                ans.push_back(maxi);
                continue;
            }
            while(maxi != -1 && (heights[maxi] < heights[alice] || heights[maxi] < heights[bob])){
                maxi = hs[maxi];
            }

            //TLE(951/952)
            // unordered_set<int> vis;
            // while (alice != -1) {
            //     vis.insert(alice);
            //     alice = hs[alice];
            // }

            
            // int meet = -1;
            // while (bob != -1) {
            //     if (vis.count(bob) || heights[query[0]] < heights[bob]) {
            //         meet = bob;
            //         break;
            //     }
            //     bob = hs[bob];
            // }

            // ans.push_back(meet);

            if(maxi != -1 && heights[maxi] > heights[alice] && heights[maxi] > heights[bob]) ans.push_back(maxi);
            else ans.push_back(-1);
        }

        return ans;
    }
};
