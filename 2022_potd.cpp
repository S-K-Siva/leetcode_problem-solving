#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        int rowCnt = 0;
        vector<int> row;
        int size = 0;

        if(m*n != original.size()) return {};
        for(int i = 0;i<original.size();i++){
            row.push_back(original[i]);
            ++size;
            if(size == n){
                result.push_back(row);
                size = 0;
                
                while(row.size()){
                    row.pop_back();
                }
            }
        }
        return result;
        
    }
};
