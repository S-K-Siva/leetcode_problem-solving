#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> rows;
        int cnt = 0;
        int n = grid.size();
        for(int i = 0;i<n;i++){
            vector<int> record;
            for(int j = 0;j<n;j++){
                record.push_back(grid[i][j]);
            }
            rows.push_back(record);
        }

        for(int i = 0;i<n;i++){
            vector<int>record;
            for(int j = 0;j<n;j++){
                record.push_back(grid[j][i]);
            }
            int rowCnt = count(rows.begin(),rows.end(),record);
            if(rowCnt){ 
                cnt += rowCnt;
            }
        }
        return cnt;
    }
};