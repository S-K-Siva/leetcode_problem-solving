#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:


    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // base case, 
        vector<vector<int>> res(m,vector<int>(n,-1));

        vector<vector<int>> visited(m,vector<int>(n,0));
        
        int row = 0,col = 0;
        char dir = 'R';
        ListNode *temp;
        temp = head;
        while(temp != nullptr && row >= 0 && row < m && col >= 0 && col < n){
            if(visited[row][col]) break;
            res[row][col] = temp->val;
            visited[row][col] = 1;
            if((dir == 'R' && (col+1 >= n || visited[row][col+1] == 1))){
                dir = 'D';
            }
            if((dir == 'D' && (row+1 >= m || visited[row+1][col] == 1))){
                dir = 'L';
            }
            if((dir == 'L' && (col-1 < 0 || visited[row][col-1] == 1))){
                dir = 'U';
            }
            if((dir == 'U' && (row-1 < 0 || visited[row-1][col] == 1))){
                dir = 'R';
            }
            if(dir == 'D'){
                row++;
            }
            if(dir == 'U'){
                row--;
            }
            if(dir == 'L'){
                col--;
            }
            if(dir == 'R'){
                col++;
            }
            temp = temp->next;
        }
        return res;
    }
};
