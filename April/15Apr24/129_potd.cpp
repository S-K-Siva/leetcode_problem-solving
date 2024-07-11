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

    void helper(vector<int>&res,TreeNode* root,int num){
        cout << num << endl;
        if(root->left == NULL && root->right == NULL){
            num = (num*10)+root->val;
            res.push_back(num);
            return;
        }
        if(root->left)
            helper(res,root->left,(num*10)+root->val);
        if(root->right)
            helper(res,root->right,(num*10)+root->val);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> result;
        helper(result,root,0);
        return accumulate(result.begin(),result.end(),0);
    }
};