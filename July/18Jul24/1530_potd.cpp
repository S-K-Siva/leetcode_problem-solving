#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    // map takes more time, accessing time is O(log n), where as in vector O(1)
    // unordered_map<int,int> solve(TreeNode* root, int distance,int& result){

    //     if(root == NULL){
    //         return unordered_map<int,int>();
    //     }
    //     else if(root->left == NULL && root->right == NULL){
    //         unordered_map<int,int> current;
    //         current[1] = 1;
    //         return current;
    //     }

    //     unordered_map<int,int> left,right;
    //     left = solve(root->left,distance,result);
    //     right = solve(root->right,distance,result);

    //     for(auto it : left){
    //         for(auto it1 : right){
    //             if(it.first + it1.first <= distance){
    //                 result += it.second * it1.second;
    //             }
    //         }
    //     }
    //     unordered_map<int,int> allDistances;
    //     for(auto it : left){
    //         if(it.first + 1 <= distance)
    //             allDistances[it.first + 1] += it.second;
    //     }
    //     for(auto it : right){
    //         if(it.first + 1 <= distance)
    //             allDistances[it.first + 1] += it.second;
    //     }
    //     return allDistances;
    // }

    // vector<int> solve(TreeNode* root, int distance,int& result){
    //     if(root == nullptr) return {};
    //     if(root->left == nullptr && root->right == nullptr) return {1};

    //     vector<int> left,right;
    //     left = solve(root->left,distance,result);
    //     right = solve(root->right,distance,result);

    //     for(int i = 0;i<left.size();i++){
    //         for(int j = 0;j<right.size();j++){
    //             if(left[i]+right[j] <= distance){
    //                 result++;
    //             }
    //         }
    //     }

    //     vector<int> mergeLeftRight;
    //     for(int i = 0;i<left.size();i++){
    //         if(left[i] + 1 <= distance){
    //             mergeLeftRight.push_back(left[i]+1);
    //         }

    //     }
    //     for(int i = 0;i<right.size();i++){
    //         if(right[i]+1 <= distance){
    //             mergeLeftRight.push_back(right[i]+1);
    //         }
    //     }
    //     return mergeLeftRight;
    // }
    // making it bit more optimal
    vector<int> solve(TreeNode* root, int distance, int& result) {
        if (root == nullptr) return vector<int>(distance + 1, 0);
        if (root->left == nullptr && root->right == nullptr) {
            vector<int> current(distance + 1, 0);
            current[1] = 1;
            return current;
        }

        vector<int> left = solve(root->left, distance, result);
        vector<int> right = solve(root->right, distance, result);

        for (int i = 1; i <= distance; ++i) {
            for (int j = 1; j <= distance; ++j) {
                if (i + j <= distance) {
                    result += left[i] * right[j];
                }
            }
        }

        vector<int> mergeLeftRight(distance + 1, 0);
        for (int i = 1; i < distance; ++i) {
            mergeLeftRight[i + 1] += left[i];
            mergeLeftRight[i + 1] += right[i];
        }
        return mergeLeftRight;
    }
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        solve(root,distance,result);
        return result;
    }
};