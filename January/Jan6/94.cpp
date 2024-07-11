#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void inorderTraversal(vector<int>& arr, TreeNode* root){
        if(root == NULL) return;

        inorderTraversal(arr,root->left);
        arr.push_back(root->val);
        inorderTraversal(arr,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal(result,root);
        return result;
        
    }
};