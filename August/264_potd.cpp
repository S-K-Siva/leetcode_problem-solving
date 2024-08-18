#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> dp;
//         dp.push_back(1);
//         set<int> seen;
//         seen.insert(1);
//         int index = 0;
//         while(dp.size() != n) {
//             int current = dp[index];
//             vector<int> vals = {current * 2, current * 3, current * 5};
//             for(int i = 0; i < vals.size(); i++) {
//                 if(seen.find(vals[i]) == seen.end()) {
//                     dp.push_back(vals[i]);
//                     seen.insert(vals[i]);
//                 }
//             }
//             index++;
//         }
        
//         sort(dp.begin(), dp.end());
//         return dp[n-1];
//     }
// };
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        set<long> vis;
        minHeap.push(1);
        vis.insert(1);
        
        long ugly = 1;
        
        
        for (int i = 0; i < n; i++) {
            ugly = minHeap.top();
            minHeap.pop();
            
            if (vis.find(ugly * 2) == vis.end()) {
                minHeap.push(ugly * 2);
                vis.insert(ugly * 2);
            }
            if (vis.find(ugly * 3) == vis.end()) {
                minHeap.push(ugly * 3);
                vis.insert(ugly * 3);
            }
            if (vis.find(ugly * 5) == vis.end()) {
                minHeap.push(ugly * 5);
                vis.insert(ugly * 5);
            }
        }
        
        return ugly;
    }
};
