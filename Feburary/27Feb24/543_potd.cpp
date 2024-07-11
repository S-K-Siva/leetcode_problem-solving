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
    int maxx = INT_MIN;
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }else
        {
            int a = helper(root->left);
            int b = helper(root->right);
            maxx = max(maxx,a+b);
            return max(a,b)+1;
        }

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a = helper(root->left);
        int b = helper(root->right);
        maxx = max(maxx,a+b);
        return maxx;
    }
};