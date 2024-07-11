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

    bool solve(TreeNode* root, int targetSum, int currentSum){
        if(currentSum == targetSum && root->left == NULL && root->right == NULL) return true;
        
        if(root->left && solve(root->left,targetSum,currentSum + root->left->val)){
            return true;
        }
        if(root->right && solve(root->right,targetSum,currentSum + root->right->val)){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root)
            return solve(root,targetSum,root->val);
        return false;
    }
};