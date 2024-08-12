#include<bits/stdc++.h>
using namespace std;


/*

Solved through reference...

It's same as No.Of.Islands(leetcode 200)


TC : O(N^2)
SC : O(N^2)

*/
class Solution {
public:
    void DFS(int row, int col, vector<vector<int>>& visited) {
        if(row<0 || row>=visited.size() || col<0 || col>=visited[0].size() || visited[row][col]==1) return;
        visited[row][col]=1;
        DFS(row, col-1, visited);        // Left
        DFS(row, col+1, visited);        // Right
        DFS(row-1, col, visited);        // Up
        DFS(row+1, col, visited);        // Down
    }

    int regionsBySlashes(vector<string>& grid) {
        int row=grid.size(), col=grid[0].size(), result=0;
        vector<vector<int>> visited(row*3, vector<int>(col*3, 0));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                /* Changing '/' to 3X3 visited  0 0 1
                                                0 1 0
                                                1 0 0
                */
                if(grid[i][j]=='/') {
                    visited[i*3][j*3+2]=1;
                    visited[i*3+1][j*3+1]=1;
                    visited[i*3+2][j*3]=1;
                }
                /* '\\' is treated as char because first character is skipped by compiler */
                else if(grid[i][j]=='\\') {
                    visited[i*3][j*3]=1;
                    visited[i*3+1][j*3+1]=1;
                    visited[i*3+2][j*3+2]=1;
                }
                /* Changing '\\' to 3X3 visited 1 0 0
                                                0 1 0
                                                0 0 1
                */
            }
        }
        for(int i=0; i< (row * 3); i++) {
            for(int j=0; j< (col * 3); j++) {
                if(visited[i][j]==0) {
                    DFS(i, j, visited);
                    result++;
                }
            }
        }
        return result;
    }
};

