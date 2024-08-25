#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int>& res, TreeNode* root){
        if(root == NULL){
            return;
        }
        solve(res,root->left);
        solve(res,root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(result,root);
        return result;
    }
};
