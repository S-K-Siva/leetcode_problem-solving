#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                dp[row][col] = matrix[row][col];

                if(row > 0)
                    dp[row][col] += dp[row - 1][col];
                if(col > 0)
                    dp[row][col] += dp[row][col - 1];
                if(row > 0 and col > 0)
                    dp[row][col] -= dp[row - 1][col - 1];
            }
        }

        int result = 0;

        for(int startRow = 0; startRow < rows; startRow++){
            for(int endRow = startRow; endRow < rows; endRow++){
                for(int startCol = 0; startCol < cols; startCol++){
                    for(int endCol = startCol; endCol < cols; endCol++){
                        int currentValue = dp[endRow][endCol];

                        if(startCol > 0)
                            currentValue -= dp[endRow][startCol - 1];
                        if(startRow > 0)
                            currentValue -= dp[startRow - 1][endCol];
                        if(startRow > 0 and startCol > 0)
                            currentValue += dp[startRow - 1][startCol - 1];

                        result += currentValue == target;
                    }
                }
            }
        }

        return result;
    }
};