#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // vector<int> result;
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for(int i = 0;i<row;i++){
        //     int minimum_element = *min_element(matrix[i].begin(),matrix[i].end());
            
        //     for(int j = 0;j<col;j++){
        //         if(matrix[i][j] == minimum_element){
        //             int max_element = minimum_element;
        //             for(int k = 0;k<row;k++){
        //                 max_element = max(max_element,matrix[k][j]);
        //             }
        //             if(max_element == matrix[i][j]){
        //                 return {matrix[i][j]};
        //             }
                    
        //         }
        //     }
        // }
        // return {};

        // Optimal
        /*
        Though it beats less percentage of users... The optimal code is more efficient with a time complexity of O(m * n) compared to the commented-out code's O(m^2 * n), making it preferable for larger matrices despite using extra space.
        */
        map<int,int> columnMax,rowMin;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        // column -> maxi
        for(int col = 0;col<colSize;col++){
            int maxElement = INT_MIN;
            for(int row = 0;row<rowSize;row++){
                maxElement = max(maxElement,matrix[row][col]);
            }
            columnMax[col] = maxElement;
        }
        // row -> mini
        for(int row = 0;row < rowSize;row++){
            int minElement = INT_MAX;
            for(int col = 0;col< colSize;col++){
                minElement = min(minElement,matrix[row][col]);
            }
            rowMin[row] = minElement;
        }
        
        for(int i = 0;i<rowSize;i++){
            for(int j = 0;j<colSize;j++){
                if(rowMin[i] == columnMax[j] && matrix[i][j] == rowMin[i]){
                    return {matrix[i][j]};
                }
            }
        }
        return {};


    }
};