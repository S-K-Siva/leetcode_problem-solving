#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;


        int row = grid.size();
        int col = grid[0].size();

        for(int i = 1;i<row-1;i++){
            for(int j = 1;j<col-1;j++){
                set<int> rowSum,colSum,diagonalSum;
                vector<bool> vis(10,0);
                int count = 0;
                int element = grid[i][j];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;
                element = grid[i+1][j];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;
                element = grid[i-1][j];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;
                element = grid[i][j-1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                element = grid[i+1][j-1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                element = grid[i-1][j-1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                element = grid[i][j+1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                element = grid[i+1][j+1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                element = grid[i-1][j+1];
                if(element < 1 || element > 9) continue;
                if(vis[element]) continue;
                count++;
                vis[element] = 1;

                

                int constantRowSum = grid[i-1][j] + grid[i-1][j-1] + grid[i-1][j+1];
            
                if(constantRowSum != grid[i][j] + grid[i][j-1] + grid[i][j+1]) continue;
                if(constantRowSum != grid[i+1][j] + grid[i+1][j-1] + grid[i+1][j+1]) continue;
                if(constantRowSum != grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1]) continue;
                if(constantRowSum != grid[i-1][j] + grid[i][j] + grid[i+1][j]) continue;
                if(constantRowSum != grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1]) continue;
                if(constantRowSum != grid[i][j] + grid[i-1][j-1] + grid[i+1][j+1]) continue;
                if(constantRowSum != grid[i][j]+ grid[i-1][j+1] + grid[i+1][j-1]) continue;
                

                if(count == 9){
                    result++;
                }
            }
        }

        return result;
    }
};